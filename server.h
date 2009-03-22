#ifndef SERVER_H
#define SERVER_H

#include <QTcpServer>
#include <QList>

class ServerConnectionThread;

class Server : public QTcpServer
{
    Q_OBJECT
public:
    Server(QObject * parent = NULL, int port = 7890);
    ~Server();

public slots:
    void start();
    void stop();
    // send to all
    void propagate(const QString &);
    // delete dead connection from list
    void findDead();

signals:
    // emitted when error occures, should be catched by UI to show message
    void error(const QString &);

protected:
    // here we're gonna create connection in its own thread
    void incomingConnection(int handle);

private:
    int port;
    QList<ServerConnectionThread *> connections;
};

#endif // SERVER_H
