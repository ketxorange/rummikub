#include "server.h"

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "serverthread.h"
#include "serverprops.h"

#include <QTextEdit>
#include <QMenuBar>
#include <QMenu>
#include <QAction>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindowClass), serverThread(NULL)
{
    //ui->setupUi(this);
    QMenuBar * bar = this->menuBar();
    QMenu * menuGame = bar->addMenu("Game");
    menuGame->addAction("Connect to Server");
    menuGame->addAction("Disconnect from Server");
    menuGame->addSeparator();
    menuGame->addAction("Start Server", this, SLOT(startServer()));
    menuGame->addAction("Stop Server", this, SLOT(stopServer()));
    console = new QTextEdit(this);
    this->setCentralWidget(console);
}

MainWindow::~MainWindow()
{
    stopServer();
    delete ui;
}

void MainWindow::startServer()
{
    if(! serverThread) {
        ServerProps props(this);
        if(props.exec() == QDialog::Accepted)
        {
            serverThread = new ServerThread(props.getPort(), props.getRoundTime());
            connect(serverThread, SIGNAL(error(QString)), console, SLOT(append(QString)));
            serverThread->start();
        }
    }
}

void MainWindow::stopServer()
{
    if(serverThread)
    {
        serverThread->exit();
        serverThread->wait();
        delete serverThread;
        serverThread = NULL;
    }
}
