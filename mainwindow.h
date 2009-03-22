#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class Server;
class QTextEdit;

namespace Ui
{
    class MainWindowClass;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void startServer();
    void stopServer();

    void print(const QString & message);

signals:
    void sendToAll(const QString & message);

private:
    Ui::MainWindowClass *ui;
    Server * server;
    QTextEdit * console;
};

#endif // MAINWINDOW_H
