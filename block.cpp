#include "block.h"

Block::Block(int val, blockColor col, BlockContainer *bParent, bool jocker):value(val), color(col), blockParent(bParent), isJocker(jocker)
{
}

/**
  returns color of the Block
  */
blockColor Block::getColor()
{
    return color;
}

/**
  returns value on the Block
  */
int Block::getValue()
{
    return value;
}
/**
  moves block (removing it from previous group) to new group
  */
void Block::move(BlockContainer *newParent)
{
    if(blockParent!=NULL)
        blockParent->remove(this);
    newParent->add(this);
}

/**
  used to sort blocks in groups which are auto sorted
  */
bool Block::operator<(Block & b1)
{
    return (getColor() == b1.getColor()) && (getValue() < b1.getValue());
}

/**
  accessor used to set block parent
  */
void Block::setBlockParent(BlockContainer *bp)
{
    this->blockParent=bp;
}
