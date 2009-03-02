#include "blockrandom.h"

BlockRandom::BlockRandom()
{
    // wypelnianie kontenera wszystkimi mozliwymi klockami
    BlockContainer *pointer = this;
    for(int i=1;i<27;++i)
        this->add(new Block(i%27, RED, pointer, false));

    for(int i=1;i<27;++i)
        this->add(new Block(i%27, ORANGE, pointer, false));

    for(int i=1;i<27;++i)
        this->add(new Block(i%27, BLUE, pointer, false));

    for(int i=1;i<27;++i)
        this->add(new Block(i%27, BLACK, pointer, false));

    this->add(new Block(0, RED, this, true));
    this->add(new Block(1, BLACK, this, true));

    srandom(time(NULL));

}

Block * BlockRandom::getRandomBlock()
{
    Block *toReturn = blockList[random()%blockList.size()];
    this->remove(toReturn);
    return toReturn;
}
