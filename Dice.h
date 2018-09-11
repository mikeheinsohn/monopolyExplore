#pragma once
#include <random>

using namespace std;

class Dice
{
public:

	Dice();
	~Dice();

	bool gotTripleDoubles();
	int numTimesRolled();
	int rollResult();
	void clearDoubles();
	void roll();

private:
	random_device rd;
	int dice1;
	int dice2;
	int numDoubles;
	int timesRolled;

};
