#ifndef BLOCKRANDOM_H
#define BLOCKRANDOM_H

#include "blockcontainer.h"
#include "block.h"
#include <cstdlib>

class BlockRandom : public BlockContainer
{
public:
    BlockRandom();
    Block *getRandomBlock();
};

#endif // BLOCKRANDOM_H
