#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "die.h"
#include "roll.h"
#include "shooter.h"
#include "come_out_phase.h"
#include "point_phase.h"

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

TEST_CASE("Die roll returns values from 1 to 6") {
	Die die;
	for (int i = 0; i < 10; ++i) {
		int result = die.roll();
		REQUIRE(result >= 1);
		REQUIRE(result <= 6);
	}
}

TEST_CASE("Roll returns values from 2 to 12") {
	Die die1;
	Die die2;
	Roll roll(die1, die2);
	for (int i = 0; i < 10; ++i) {
		roll.roll_dice();
		int result = roll.roll_value();
		REQUIRE(result >= 2);
		REQUIRE(result <= 12);
	}
}

TEST_CASE("Shooter return Roll with value between 2 and 12"){
	Die d1;
	Die d2;
	Shooter shooter1;

	for(int i=0; i<10; ++i){
		Roll* roll = shooter1.throw_dice(d1, d2);

		REQUIRE(roll != nullptr);

		int value = roll->roll_value();
		REQUIRE(value >= 2);
		REQUIRE(value <= 12);

	}
	
}

TEST_CASE("COMEOUTPHASE returns natural, craps, and point outcomes"){

	Die d1;
	Die d2;
	Shooter shooter;
	ComeOutPhase comeOutPhase;

	bool saw_natural = false;
	bool saw_craps = false;
	bool saw_point = false;

	for (int i = 0; i < 20; ++i) {
		Roll* roll = shooter.throw_dice(d1, d2);
		RollOutcome outcome = comeOutPhase.get_outcome(roll);
		
		if(outcome == RollOutcome::natural) 
		{	saw_natural = true;	}
		else if(outcome == RollOutcome::craps) 
		{	saw_craps = true;	}
		else if(outcome == RollOutcome::point) 
		{	saw_point = true;	}

	}
	REQUIRE(saw_natural);
	REQUIRE(saw_craps);
	REQUIRE(saw_point);


}

TEST_CASE("POINTPHASE returns point, seven_out, and nopoint outcomes"){

	Die d1;
	Die d2;
	Shooter shooter;

	int test_point = 5;
	PointPhase pointPhase(test_point);

	bool saw_point = false;
	bool saw_seven_out = false;
	bool saw_nopoint = false;

	// Simulate rolls until all outcomes are seen
	for (int i = 0; i < 50; ++i) {
		Roll* roll = shooter.throw_dice(d1, d2);
		RollOutcome outcome = pointPhase.get_outcome(roll);
		
		if(outcome == RollOutcome::point) 
		{	saw_point = true;	}
		else if(outcome == RollOutcome::seven_out) 
		{	saw_seven_out = true;	}
		else if(outcome == RollOutcome::nopoint) 
		{	saw_nopoint = true;	}

		if(saw_point && saw_seven_out && saw_nopoint) {
			break; // Exit early if all outcomes have been seen
		}
	}

	REQUIRE(saw_point);
	REQUIRE(saw_seven_out);
	REQUIRE(saw_nopoint);

}


