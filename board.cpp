#include "board.h"

Board::Board()
{
}

Board::~Board()
{
    for(QList<BlockGroup*>::Iterator it = groupList.begin(); it!=groupList.end(); it++)
        delete *it;
}

/**
  creates Group on board and returns it's uniqe id on the list
  */
int Board::createGroup()
{
    BlockGroup* newGroup = new BlockGroup();
    groupList.append(newGroup);

    return groupList.indexOf(newGroup);
}


/**
  validates whole board
  */
bool Board::isValid()
{
    for(QList<BlockGroup*>::Iterator it = groupList.begin(); it!=groupList.end(); it++)
        if(!(*it)->isValid())
            return false;
    return true;
}




