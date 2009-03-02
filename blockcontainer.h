#ifndef BLOCKCONTAINER_H
#define BLOCKCONTAINER_H

#include <QObject>
#include <QList>
#include <QListIterator>
#include "block.h"

class Block;

class BlockContainer : public QObject
{
    Q_OBJECT
public:
    BlockContainer();
    ~BlockContainer();

public slots:
    void add(Block*);
    void remove(Block*);
    void moveTo(BlockContainer*, Block*);

protected:
    QList<Block*> blockList;
};

#endif // BLOCKCONTAINER_H
