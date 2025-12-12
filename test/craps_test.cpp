#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "die.h"
#include "roll.h"
#include "shooter.h"

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



