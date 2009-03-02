#include "block.h"

Block::Block(int val, blockColor col, BlockContainer *bParent, bool jocker):value(val), color(col), blockParent(bParent), isJocker(jocker)
{
}




blockColor Block::getColor()
{
    return color;
}

int Block::getValue()
{
    return value;
}

void Block::move(BlockContainer *newParent)
{
    if(blockParent!=NULL)
        blockParent->remove(this);
    newParent->add(this);
}

bool Block::operator<(Block & b1)
{
    return (getColor() <= b1.getColor()) && (getValue() < b1.getValue());
}

void Block::setBlockParent(BlockContainer *bp)
{
    this->blockParent=bp;
}
