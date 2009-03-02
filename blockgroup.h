#ifndef BLOCKGROUP_H
#define BLOCKGROUP_H

#include <QObject>
#include <QList>
#include <QListIterator>

#include "blockcontainer.h"
#include "block.h"

class BlockGroup : public BlockContainer
{
    Q_OBJECT
public:
    BlockGroup();
    bool isValid();

};

#endif // BLOCKGROUP_H
