#ifndef SERVERTHREAD_H
#define SERVERTHREAD_H

#include <QThread>

class ServerThread : public QThread
{
    Q_OBJECT
public:
    ServerThread(int port, int roundTime);
    void run();

public slots:
    void emiterror(const QString &);
signals:
    void error(const QString &);

private:
    int port, roundTime;
};

#endif // SERVERTHREAD_H
