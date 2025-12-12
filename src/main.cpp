#include <iostream>
#include <cstdlib>
#include <ctime>

#include "die.h"
#include "roll.h"
#include "shooter.h"
#include "come_out_phase.h"
#include "point_phase.h"



int main()
{
	srand(time(0)); 
	

	Die die1;
	Die die2;
	Shooter shooter;

	Roll* roll = shooter.throw_dice(die1, die2);
	int roll_value = roll->roll_value();

	ComeOutPhase comeOutPhase;
	RollOutcome outcome = comeOutPhase.get_outcome(roll);

	while (outcome == RollOutcome::natural ||
			outcome == RollOutcome::craps) 
	{
		
		std::cout << "Come Out Roll: " << roll_value << " - ";

		roll = shooter.throw_dice(die1, die2);
		roll_value = roll->roll_value();
		outcome = comeOutPhase.get_outcome(roll);
		
	}
	
	std::cout <<"Rolled " << roll_value << " Start of point phase\n";
	std::cout << "Roll until " << roll_value << " or 7 is rolled.\n";

	int point = roll_value;

	PointPhase pointPhase(point);

	roll = shooter.throw_dice(die1, die2);
	roll_value = roll->roll_value();
	outcome = pointPhase.get_outcome(roll);

	while(outcome == RollOutcome::nopoint)
	{
		std::cout << "Point Roll: " << roll_value << " - No Point\n";

		roll = shooter.throw_dice(die1, die2);
		roll_value = roll->roll_value();
		outcome = pointPhase.get_outcome(roll);
	}

	std::cout << "Rolled " << roll_value <<  " end of point phase\n";

	shooter.display_rolled_values();
	


	
	return 0;
}