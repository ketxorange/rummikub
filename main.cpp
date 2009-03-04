#include <QtGui/QApplication>
#include "mainwindow.h"
#include "board.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Board b;
    //MainWindow w;
    //w.show();
    return a.exec();
}
