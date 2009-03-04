#include "blockcontainer.h"

BlockContainer::BlockContainer()
{
}

/**
  removes all blocks in list - no blocks without parent - no memory leek problem
  */
BlockContainer::~BlockContainer()
{
    QList<Block*>::Iterator it = blockList.begin();
    while(it != blockList.end())
    {
        delete *it;
    }
}

/**
  adds block to this container auto-sorting
  */
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

/**
  removes block from container setting parent to NULL
  */
void BlockContainer::remove(Block *b)
{
    b->setBlockParent(NULL);
    blockList.removeOne(b);
}

/**
  moves block from this container to another using block function
  */
void BlockContainer::moveTo(BlockContainer *bc, Block *b)
{
    b->move(bc);
}

/**
  moves block blockNr to bc block container
  */
void BlockContainer::moveTo(BlockContainer *bc, int blockNr)
{
    blockList[blockNr]->move(bc);
}

bool BlockContainer::isEmpty()
{
    return blockList.isEmpty();
}

void BlockContainer::debugPrint()
{

    QList<Block*>::Iterator it = blockList.begin();
    qDebug() << blockList.size();
    while(it != blockList.end())
    {
        QString blockStr;
        if((*it)->getColor() == BLUE)
            blockStr = "(Blue)";
        if((*it)->getColor() == BLACK)
            blockStr = "(Black)";
        if((*it)->getColor() == RED)
            blockStr = "(Red)";
        if((*it)->getColor() == ORANGE)
            blockStr = "(Orange)";
        QString val;
        val.setNum((*it)->getValue() );
        qDebug() << blockStr+" "+val;

        it++;
    }
}
