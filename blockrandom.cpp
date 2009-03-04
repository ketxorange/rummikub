#include "blockrandom.h"

/**
  fills container with complete set of blocks
  */
BlockRandom::BlockRandom()
{
    // wypelnianie kontenera wszystkimi mozliwymi klockami
    BlockContainer *pointer = this;
    for(int i=1;i<14;++i)
        this->add(new Block(i, RED, pointer, false));
    for(int i=1;i<14;++i)
        this->add(new Block(i, RED, pointer, false));

    for(int i=1;i<14;++i)
        this->add(new Block(i, ORANGE, pointer, false));
    for(int i=1;i<14;++i)
        this->add(new Block(i, ORANGE, pointer, false));

    for(int i=1;i<14;++i)
        this->add(new Block(i, BLUE, pointer, false));
    for(int i=1;i<14;++i)
        this->add(new Block(i, BLUE, pointer, false));

    for(int i=1;i<14;++i)
        this->add(new Block(i, BLACK, pointer, false));
    for(int i=1;i<14;++i)
        this->add(new Block(i, BLACK, pointer, false));


    this->add(new Block(0, RED, this, true));
    this->add(new Block(0, BLACK, this, true));

    srandom(time(NULL));

}

/**
  returns random block pointer removing! it from this container
  */
Block * BlockRandom::getRandomBlock()
{
    Block *toReturn = blockList[random()%blockList.size()];
    this->remove(toReturn);
    return toReturn;
}
