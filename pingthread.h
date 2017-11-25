#ifndef PINGTHREAD_H
#define PINGTHREAD_H

#include "QThread"

class PingThread: public QThread
{
    Q_OBJECT
    QString ip_addr;
    void run();
public:
    PingThread(QString ip_addr, QObject *parent):
        QThread(parent),ip_addr(ip_addr){}
signals:
    void Result(PingThread *thread, QString ip_addr, QString time);
};

#endif // PINGTHREAD_H
