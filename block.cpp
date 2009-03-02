#include "block.h"

Block::Block(int val, blockColor col, BlockContainer *bParent=NULL):value(val), color(col), blockParent(bParent)
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
    blockParent=newParent;
}

bool Block::operator<(Block & b1)
{
    return (getColor() <= b1.getColor()) && (getValue() < b1.getValue());
}
