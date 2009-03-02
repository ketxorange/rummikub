#include "blockcontainer.h"

BlockContainer::BlockContainer()
{
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
    blockList.insert(it, b);
}

void BlockContainer::remove(Block *b)
{
    blockList.removeOne(b);
}

void BlockContainer::moveTo(BlockContainer *bc, Block *b)
{
    b->move(bc);
}


