#include "server.h"

#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QTextEdit>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindowClass), server(NULL)
{
    //ui->setupUi(this);
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
    server->stop();
    delete server;
    server = NULL;
}

void MainWindow::print(const QString & message) {}
