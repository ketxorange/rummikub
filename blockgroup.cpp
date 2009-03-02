#include "blockgroup.h"

BlockGroup::BlockGroup()
{
}

bool BlockGroup::isValid()
{
    if(blockList.size() < 3)
        return false;

    bool isSequence = true;
    blockColor groupColor;
    if((groupColor = blockList[0]->getColor()) == blockList[1]->getColor())
        isSequence = false;


    if(!isSequence)
        for(QList<Block*>::Iterator it=blockList.begin() ; it != blockList.end() ; it++)
            for(QList<Block*>::Iterator it1 = it+1; it1 != blockList.end(); it++)
                if((*it)->getColor() == (*it1)->getColor())
                    return false;

    else
    {
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
