#include "serverconnectionthread.h"

#include <QTcpSocket>
#include <QMutexLocker>

ServerConnectionThread::ServerConnectionThread(QObject * parent, int handle)
        : QThread(parent), handle(handle), alive(true)
{}

ServerConnectionThread::~ServerConnectionThread()
{
    // this invoked from another thread, not "this" thread
    aliveLock.lock();
    alive = false;
    aliveLock.unlock();

    wait();
}

void ServerConnectionThread::run()
{
    QTcpSocket socket;
    if( ! socket.setSocketDescriptor(handle))
    { // don't know if necessary
        emit error(socket.errorString());
        return;
    }
    socket.waitForConnected(-1);

    while(socket.state() != QAbstractSocket::UnconnectedState)
    {
        while(socket.waitForReadyRead(50)) // 200ms is probably to much but safe
        {
            // TODO: use text codec to convert from utf8
            // maybe not necessary
            emit clientSends(QString(socket.readAll()), handle);
        }

        while(! queue.empty())
        {
            QMutexLocker lock(&queueLock); // blokuje i zwalnia na koncu tego zasiegu
            socket.write(queue.dequeue().toUtf8());
        }

        QMutexLocker lock(&aliveLock);
        if(! alive) return;
    }
}

void ServerConnectionThread::tellClient(const QString & str)
{
    QMutexLocker lock(&queueLock);
    queue.enqueue(str);
}

int ServerConnectionThread::getHandle()
{
    return handle;
}
