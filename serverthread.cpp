#include "serverthread.h"
#include "server.h"

ServerThread::ServerThread(int port, int roundTime)
        : port(port), roundTime(roundTime)
{}

void ServerThread::run()
{
    Server server(port, roundTime);
    connect(&server, SIGNAL(error(QString)), this, SLOT(emiterror(QString)));

    server.start();

    exec();
}

void ServerThread::emiterror(const QString & message)
{
    emit error(message);
}
