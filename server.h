#ifndef SERVER_H
#define SERVER_H

#include <QTcpServer>
#include <QList>

class ServerConnectionThread;

class Server : public QTcpServer
{
    Q_OBJECT
public:
    Server(int port, int roundTime, QObject * parent = NULL);
    ~Server();

public slots:
    void start();
    void stop();
    // send to all
    void propagate(const QString &, int clientHandle);
    // delete dead connection from list
    void findDead();

signals:
    // emitted when error occures, should be catched by UI to show message
    void error(const QString &);

protected:
    // here we're gonna create connection in its own thread
    void incomingConnection(int handle);

private:
    int port, roundTime;
    QList<ServerConnectionThread *> connections;
};

#endif // SERVER_H
