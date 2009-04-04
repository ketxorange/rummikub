#include "blockgroup.h"

BlockGroup::BlockGroup()
{
}

/**
  return wheather group is valid or not
  TODO: add jocker actions
  */
bool BlockGroup::isValid()
{
    if(blockList.size() < 3)
        return false;

    //checking if seqence
    bool isSequence = false;
    blockColor groupColor;
    if((groupColor = blockList[0]->getColor()) == blockList[1]->getColor())
        isSequence = true;


    if(!isSequence)//checking (same value - different colours)
    {
        //qDebug() << "Not sequence!";
        for(QList<Block*>::Iterator it=blockList.begin() ; it != blockList.end() ; it++)
            for(QList<Block*>::Iterator it1 = it+1; it1 != blockList.end(); it1++)
                if((*it)->getColor() == (*it1)->getColor())
                    return false;

    }

    else//checking sequence values - same color
    {
        //qDebug() << "Sequence!";
        for(QList<Block*>::Iterator it = blockList.begin(); it != blockList.end(); it++)
            if((*it)->getColor() != groupColor)
                return false;


        QList<Block*>::Iterator it = blockList.begin();
        int lastValue = (*it)->getValue();
        it++;
        while( it != blockList.end() )
        {
            if((*it)->getValue() - lastValue != 1)
                return false;
            else
                lastValue = (*it)->getValue();
            it++;
        }
    }
    return true;

}
