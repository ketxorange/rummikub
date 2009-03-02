#include "blockrandom.h"

BlockRandom::BlockRandom()
{
    // wypelnianie kontenera wszystkimi mozliwymi klockami
    BlockContainer *pointer = this;
    for(int i=1;i<27;++i)
        this->add(new Block(i%27, RED, pointer));

    /*this->add(new Block(0, 0, this, true));
    this->add(new Block(1, 0, this, true));*/
}
