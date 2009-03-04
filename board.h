#ifndef BOARD_H
#define BOARD_H

#include <QObject>
#include <QList>
#include "blockgroup.h"
#include "blockrandom.h"

class Board : public QObject
{
public:
    Board();
    ~Board();
    int createGroup();
//    void deleteEmptyGroups();
    bool isValid();


private:
    QList<BlockGroup *> groupList;

};

#endif // BOARD_H
