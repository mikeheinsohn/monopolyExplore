#include <random>
#include <iostream>
#include <iomanip>
#include "Dice.h"

using namespace std;

Dice::Dice()
{
	dice1 = 0;
	dice2 = 0;
	timesRolled = 0;
	clearDoubles();
}


Dice::~Dice()
{
	// Nothing now
}


bool Dice::gotTripleDoubles()
{
	if (numDoubles == 3)
	{
		return true;
	}
	else
	{
		return false;
	}
}


int Dice::numTimesRolled()
{
	return timesRolled;
}


int Dice::rollResult()
{
	return dice1 + dice2;
}


void Dice::clearDoubles()
{
	numDoubles = 0;
}


void Dice::roll()
{
	timesRolled++;
	mt19937 gen(rd());
	uniform_int_distribution<> dist(1, 6);
	dice1 = dist(gen);
	dice2 = dist(gen);

	if (dice1 == dice2) {
		numDoubles++;
	}
	else {
		clearDoubles();
	}
}
