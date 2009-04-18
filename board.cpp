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
  moves block nr block in source group to destination group
  TODO - czy source/dest istnieje
  */
bool Board::move(int block, int source, int destination)
{
    if(groupList.size() > block)
    {
        groupList[source]->moveTo(groupList[destination], block);
        if(groupList[source]->isEmpty())
        {
            groupList.removeAt(source);
        }
    }
    else
        return false;
    return true;
}

/**
  moves block nr block in source to destination(pointer, if NULL creates new group)
  */
bool Board::move(int block, int source, BlockGroup *dest)
{
    bool toRet;
    if(dest == NULL)
    {
        toRet = move(block, source, createGroup());
    }
    else
    {
        toRet = move(block, source, groupList.indexOf(dest));
    }
    return toRet;
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

void Board::debugPrint()
{
    for(int  i=0; i<groupList.size(); i++)
    {
        QString str;

        qDebug() << "######### "+ QString::number(i) + " ##########";
        groupList[i]->debugPrint();
        qDebug() << "######### # ##########";
    }
}

/**
  adds block given by server to tray
  */
void Board::addToTray(QString block)
{
    tray.add(block);
}

/**
  puts block nr n from tray on the table creating new group
  */
void Board::putOnTable(int n)
{
    tray.moveTo(groupList[createGroup()], n);
}
