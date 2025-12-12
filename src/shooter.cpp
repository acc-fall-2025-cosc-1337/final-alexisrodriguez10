#include "shooter.h"
#include <iostream>

Roll*Shooter::throw_dice(Die& d1, Die& d2) 
{
    Roll* new_roll = new Roll(d1, d2);
    
    new_roll->roll_dice();

    rolls.push_back(new_roll);

    return new_roll;
}

void Shooter::display_rolled_values() 
{
    for (auto roll_ptr : rolls) 
    {
        if(roll_ptr != nullptr)
        {

            std::cout << roll_ptr->roll_value() << " ";
        }
    }
    std::cout << std::endl;
}

Shooter::~Shooter() 
{
    for (auto roll_ptr : rolls) 
    {
        delete roll_ptr;
    }
    rolls.clear();
}