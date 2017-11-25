#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSystemTrayIcon>
#include <QTimer>
#include <QLabel>
#include <QEvent>
#include <QSystemTrayIcon>
#include <QMenu>
#include <QCloseEvent>
#include "pingthread.h"
#include <QTabWidget>
namespace Ui {
class MainWindow;
}

class PingThread;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    //PingResult(PingThread*,QString,QString);

private:
    Ui::MainWindow *ui;
    QTimer checkTime;
    QTabWidget widget;
    void AddRow(QString name, QString ip_addr);
public slots:
    void RefreshStatus();
    void PingResult(PingThread *thread,QString ip_addr, QString time);

private slots:
    void addIP_Addr();
   // void addIP_Addr();

};

#endif // MAINWINDOW_H
