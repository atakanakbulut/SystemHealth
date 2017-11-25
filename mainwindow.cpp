#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFileInfo>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QMenu>
#include <QList>
#include "pingthread.h"

#define STATUS_PINGING "pingable"
#define STATUS_IDLE "not pingable"

enum columns
{
    COLUMN_NAME,
    COLUMN_IP,
    COLUMN_TIME,
    COLUMN_STATUS
};


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
  connect(this,SIGNAL(Result(PingThread*,QString,QString)),this,SLOT(PingResult(PingThread*,QString,QString)));
    checkTime.start(1000);
    connect(&checkTime,SIGNAL(timeout()),this,SLOT(RefreshStatus()));   
    connect(ui->lineEdit, SIGNAL(returnPressed()),this, SLOT(addIP_Addr()));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::AddRow(QString name, QString ip_addr)
{
    ui->tableWidget->insertRow(0);
    ui->tableWidget->setItem(0, COLUMN_NAME, new QTableWidgetItem(name));
    ui->tableWidget->setItem(0, COLUMN_IP, new QTableWidgetItem(ip_addr));
    ui->tableWidget->setItem(0, COLUMN_TIME, new QTableWidgetItem());
    ui->tableWidget->setItem(0, COLUMN_STATUS, new QTableWidgetItem(STATUS_IDLE));
}


void MainWindow::RefreshStatus()
{
    QString ip_addr = ui->lineEdit->text();
    PingThread *p = new PingThread(ip_addr,this);
    p->start();
    connect(p,SIGNAL(Result(PingThread*,QString,QString)),this,SLOT(PingResult(PingThread*,QString,QString)));
     qDebug()<<"refreshed";

     //*******





     //------------------
      bool foundSuccess = false;
         bool foundError = false;
         for(int i=0; i<ui->tableWidget->rowCount(); i++)
         {
             QString time = ui->tableWidget->item(i,COLUMN_TIME)->text();
             if(time == NULL)
                 foundError = true;
             else
                 foundSuccess = true;
         }
}

void MainWindow::PingResult(PingThread *thread,QString ip_addr, QString time)
{
    thread->wait();
    delete thread;
    qDebug()<<ip_addr<<" time: "<<time;

    //**
    for(int i=0; i<ui->tableWidget->rowCount(); i++)
        if(ui->tableWidget->item(i,COLUMN_IP)->text() == ip_addr)
        {
            ui->tableWidget->item(i,COLUMN_STATUS)->setText(STATUS_IDLE);
            if(time == NULL)
            {

                ui->tableWidget->item(i,COLUMN_TIME)->setText(NULL);
            }
            else
            {
                ui->tableWidget->item(i,COLUMN_TIME)->setData(Qt::DisplayRole,time.toDouble());
            }
            break;
        }


    //

}

void MainWindow::addIP_Addr()
{
    QString ip_addr = ui->lineEdit->text();
    if(ip_addr.isNull() || ip_addr.isEmpty()){
        qDebug() << "null";
    }
    AddRow("aa",ip_addr);
}







