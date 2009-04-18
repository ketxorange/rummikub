#include "server.h"
#include "serverconnectionthread.h"

#include <QDebug>
#include <QMessageBox>
#include <QMutableListIterator>
#include <QTcpSocket>

Server::Server(int port, int roundTime, QObject * parent)
        : QTcpServer(parent), port(port), roundTime(roundTime)
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
    } else {
        emit error("Server started");
    }
}

void Server::stop()
{
    QMutableListIterator<ServerConnectionThread *> it(connections);
    while(it.hasNext())
    {
        ServerConnectionThread * conn = it.next();
        it.remove();
        delete conn;
    }
    emit error("Server stopped");
    close();
}


void Server::incomingConnection(int handle)
{
    qDebug() << "New Connection: " << handle;
    if(connections.size() < 4)
    {
        ServerConnectionThread * conn = new ServerConnectionThread(this, handle);
        connections.append(conn);
        connect(conn, SIGNAL(finished()), this, SLOT(findDead()));
        connect(conn, SIGNAL(clientSends(QString, int)), this, SLOT(propagate(QString, int)));
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

void Server::propagate(const QString & message, int clientHandle)
{
    QListIterator<ServerConnectionThread *> it(connections);
    while(it.hasNext())
    {
        ServerConnectionThread * thr = it.next();
        if(thr->getHandle() == clientHandle)
            thr->tellClient("FROM YOU: " + message);
        else
            thr->tellClient(QString("FROM %1: %2").arg(clientHandle).arg(message));
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
