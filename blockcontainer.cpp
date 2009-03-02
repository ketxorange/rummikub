#include "blockcontainer.h"

BlockContainer::BlockContainer()
{
}

BlockContainer::~BlockContainer()
{
    QList<Block*>::Iterator it = blockList.begin();
    while(it != blockList.end())
    {
        delete *it;
    }
}

void BlockContainer::add(Block *b)
{
    QList<Block*>::Iterator it=blockList.begin();
    while(it != blockList.end())
    {
        if(*(*it) < *b)
            it++;
        else
            break;
    }
    b->setBlockParent(this);
    blockList.insert(it, b);
}

void BlockContainer::remove(Block *b)
{
    b->setBlockParent(NULL);
    blockList.removeOne(b);
}

void BlockContainer::moveTo(BlockContainer *bc, Block *b)
{
    b->move(bc);
}


