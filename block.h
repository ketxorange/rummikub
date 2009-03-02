#ifndef BLOCK_H
#define BLOCK_H

#include <QObject>
#include "blockcontainer.h"

class BlockContainer;

/**
* type holding block colour
*/

enum blockColor { RED, BLUE, BLACK, ORANGE };


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

    void setBlockParent(BlockContainer *);

private:
    int value;
    blockColor color;

    BlockContainer *blockParent;
    bool isJocker;


};

#endif // BLOCK_H
