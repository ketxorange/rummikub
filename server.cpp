#include "server.h"
#include "serverconnectionthread.h"

#include <QDebug>
#include <QMessageBox>
#include <QMutableListIterator>
#include <QTcpSocket>

Server::Server(QObject * parent, int port)
        : QTcpServer(parent), port(port)
{}

Server::~Server()
{
    this->stop();
}

void Server::start()
{
    if(! listen(QHostAddress::Any, port))
    {
        emit error("Can't start Server");
    }
}

void Server::stop()
{ // to be written
}


void Server::incomingConnection(int handle)
{
    qDebug() << "New Connection: " << handle;
    if(connections.size() < 4)
    {
        ServerConnectionThread * conn = new ServerConnectionThread(this, handle);
        connections.append(conn);
        connect(conn, SIGNAL(finished()), this, SLOT(findDead()));
        connect(conn, SIGNAL(clientSends(const QString &)), this, SLOT(propagate(const QString &)));
        conn->start();
    } else {
        // telling client to get lost
        QTcpSocket socket(this);
        socket.setSocketDescriptor(handle);
        socket.write("GET_LOST");
        socket.waitForBytesWritten(200);
        socket.close();
    }
}

void Server::propagate(const QString & message)
{
    QListIterator<ServerConnectionThread *> it(connections);
    while(it.hasNext())
    {
        it.next()->tellClient(message);
    }
}

void Server::findDead()
{
    /* bardzo mozliwe, ze mozna to napisac bez przeszukiwania calej listy
       ale to tylko 4 elementy */
    qDebug() << "Finding Dead";
    QMutableListIterator<ServerConnectionThread *> it(connections);
    while(it.hasNext())
    {
        ServerConnectionThread * conn = it.next();
        if(conn->isFinished())
        {
            it.remove();
            qDebug() << "Found Dead: " << conn->getHandle();
            delete conn;
        }
    }
}
