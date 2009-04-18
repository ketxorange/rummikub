#include <QtGui/QApplication>
#include "mainwindow.h"
#include "board.h"
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Board b;
    BlockRandom bRand;

    bool run=true;
    while(run)
    {
        qDebug() << "1 - koniec\n2 - losuj i dodaj do tacki\n3 - przesun\n4 - przesun do nowej\n5 - wydrukuj tacke\n6 - wydrkuj stol\n7 - poloz na stol";
        int n;
        cin >> n;
        int gr, gr1;
        int kl;

        switch(n)
        {
            case 1:
              run=false;
              break;
            case 2:
              b.addToTray(bRand.getRandomBlock()->toString());
              break;
            case 3:
              qDebug() << "Grupa: ";
              cin >> gr;
              qDebug() << "Klocek: ";
              cin >> kl;
              qDebug() << "Do: ";
              cin >> gr1;
              b.move(kl, gr, gr1);
              break;
            case 4:
              qDebug() << "Grupa: ";
              cin >> gr;
              qDebug() << "Klocek: ";
              cin >> kl;
              b.move(kl, gr, (BlockGroup*)NULL);
              break;
            case 5:
              b.getTray()->debugPrint();
              break;
            case 6:
              b.debugPrint();
              break;
            case 7:
              cin >> kl;
              b.putOnTable(kl);
              break;
          }
    }

    //MainWindow w;
    //w.show();
    //return a.exec();
    return 0;
}
