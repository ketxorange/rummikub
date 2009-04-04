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
    bool move(int block, int source, int destination);
    bool move(int block, int source, BlockGroup *);
    void debugPrint();
    void addToTray(QString block);
    void putOnTable(int n);
    BlockContainer *getTray() { return &tray; }


private:
    QList<BlockGroup *> groupList;
    BlockContainer tray;

};

#endif // BOARD_H
