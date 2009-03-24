#include "server.h"

#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QTextEdit>
#include <QMenuBar>
#include <QMenu>
#include <QAction>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindowClass), server(NULL)
{
    //ui->setupUi(this);
    QMenuBar * bar = this->menuBar();
    QMenu * menuServer = bar->addMenu("Server");
    menuServer->addAction("Start Server", this, SLOT(startServer()));
    menuServer->addAction("Stop Server", this, SLOT(stopServer()));
    console = new QTextEdit(this);
    this->setCentralWidget(console);
}

MainWindow::~MainWindow()
{
    if(server) delete server;
    delete ui;
}
void MainWindow::startServer() {
    if(! server) {
        server = new Server(this);
        server->start();
        connect(server, SIGNAL(error(QString)), console, SLOT(append(QString)));
    }
}
void MainWindow::stopServer() {
    delete server;
    server = NULL;
}

void MainWindow::print(const QString & message) {}
