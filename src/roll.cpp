#include "roll.h"

Roll::Roll(Die& d1, Die& d2) : die1(d1), die2(d2) {}

void Roll::roll_dice() 
{
    int first_roll = die1.roll();
    int second_roll = die2.roll();
    value = first_roll + second_roll;
}

int Roll::roll_value() const 
{
    return value;
}