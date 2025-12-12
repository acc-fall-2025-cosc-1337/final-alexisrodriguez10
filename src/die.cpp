#include "die.h"
#include <random>

int Die::roll() 
{
    static std::random_device rd;
    static std::mt19937 engine(rd());
    std::uniform_int_distribution<int> dist(1, sides);

    return dist(engine);
}