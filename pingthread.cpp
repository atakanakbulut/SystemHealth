#include "pingthread.h"
#include "QProcess"

void PingThread::run()
{
#if defined(WIN32)
    QString parameter = "-n 1 "+ip_addr;
#else
    QString parameter = "-c 1 "+ip_addr;
#endif

    QProcess *process = new QProcess();
    process->start("ping "+parameter,QIODevice::ReadOnly);
    process->waitForFinished();
    QString text(process->readAllStandardOutput());
    delete process;

#if defined(WIN32)
    QString property("Average = ");
    int propertyIndex = text.indexOf(property);
    if(propertyIndex >= 0)
    {
        int startTime = propertyIndex + property.length();
        int endTime = text.indexOf("ms",startTime);
#else
    QString property("time=");
    int propertyIndex = text.indexOf(property);
    if(propertyIndex >= 0)
    {
        int startTime = propertyIndex + property.length();
        int endTime = text.indexOf(" ms",startTime);
#endif
        QString time = text.mid(startTime, endTime-startTime);
        emit Result(this,ip_addr,time);
    }
    else
        emit Result(this,ip_addr,NULL);
}
