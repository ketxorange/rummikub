#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class ServerThread;
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

signals:
    void sendToAll(const QString & message);

private:
    Ui::MainWindowClass *ui;
    ServerThread * serverThread;
    QTextEdit * console;
};

#endif // MAINWINDOW_H
