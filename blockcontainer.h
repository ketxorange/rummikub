#ifndef BLOCKCONTAINER_H
#define BLOCKCONTAINER_H

#include <QObject>
#include <QList>
#include <QListIterator>
#include "block.h"
#include <QDebug>
#include <QString>
#include <QStringList>

class Block;

class BlockContainer : public QObject
{
    Q_OBJECT
public:
    BlockContainer();
    ~BlockContainer();

public slots:
    void add(Block*);
    void add(QString);
    void remove(Block*);
    void moveTo(BlockContainer*, Block*);
    void moveTo(BlockContainer*, int);
    bool isEmpty();
    int size();

    void debugPrint();
protected:
    QList<Block*> blockList;
};

#endif // BLOCKCONTAINER_H
