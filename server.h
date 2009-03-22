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

signals:
    // emitted when error occures, should be catched by UI to show message
    void error(const QString &);

public slots:
    // send to all
    void propagate(const QString &);
    // delete dead connection from list
    void findDead();

protected:
    // here we're gonna create connection in its own thread
    void incomingConnection(int handle);

private:
    QList<ServerConnectionThread *> connections;
};

#endif // SERVER_H
