#ifndef BLOCK_H
#define BLOCK_H

#include <QObject>
#include "blockcontainer.h"

class BlockContainer;

/**
* type holding block colour
*/

enum blockColor { RED=0, BLUE=1, BLACK=2, ORANGE=3 };


/**
  * class holding block informations
  */
class Block : public QObject
{
    Q_OBJECT
public:
    Block(int, blockColor, BlockContainer *, bool);
    int getValue();
    blockColor getColor();

    void move(BlockContainer *);
    bool operator<(Block &);
    bool operator==(Block &);

    void setBlockParent(BlockContainer *);
    QString toString();

private:
    int value;
    blockColor color;

    BlockContainer *blockParent;
    bool isJocker;


};

#endif // BLOCK_H
