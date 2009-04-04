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
        it++;
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
        if((*(*(it))).getColor() == (*b).getColor())
        {
            if((*(*(it))).getValue() >= (*b).getValue())
                break;
            else
                it++;
        }
        else
            it++;
    }

    b->setBlockParent(this);
    blockList.insert(it++,b);
    qSort(blockList);
}

void BlockContainer::add(QString block)
{
    QStringList bl = block.split(";");
    blockColor b;
    if(bl[1] == "B")
        b=BLUE;
    else if(bl[1] == "R")
        b=RED;
    else if(bl[1] == "O")
        b=ORANGE;
    else
        b=BLACK;

    this->add(new Block(bl[0].toInt(), b, this, false));
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
    qDebug() << "Size: " + QString::number(blockList.size());
    int i=0;
    while(it != blockList.end())
    {
        QString blockStr = QString::number(i);
        if((*it)->getColor() == BLUE)
            blockStr += "(Blue)";
        if((*it)->getColor() == BLACK)
            blockStr += "(Black)";
        if((*it)->getColor() == RED)
            blockStr += "(Red)";
        if((*it)->getColor() == ORANGE)
            blockStr += "(Orange)";
        QString val;
        val.setNum((*it)->getValue() );
        qDebug() << blockStr+" "+val;

        it++;
        i++;
    }
}

int BlockContainer::size()
{
    return blockList.length();
}
