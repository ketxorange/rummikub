#ifndef SERVERCONNECTIONTHREAD_H
#define SERVERCONNECTIONTHREAD_H

#include <QThread>
#include <QMutex>
#include <QQueue>

class ServerConnectionThread : public QThread
{
    Q_OBJECT
public:
    ServerConnectionThread(QObject * parent, int handle);
    ~ServerConnectionThread();
    void run();
    int getHandle();

public slots:
    void tellClient(const QString &);

signals:
    void clientSends(const QString &);
    void error(const QString &);
    
private:
    int handle;
    bool alive;
    QQueue<QString> queue;
    QMutex queueLock, aliveLock;
};

#endif // SERVERCONNECTIONTHREAD_H
