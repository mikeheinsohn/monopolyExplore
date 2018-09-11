#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include "dice.h"
#include "globals.h"
#include "board.h"
#include "chance.h"
#include "communitychest.h"
#include "location.h"
#include "OurStats.h"

using namespace std;

int main(void)
{
	Dice theDice;
	Board theBoard;
	Location ourLocation;
	Chance chanceCards;
	CommunityChest communityChestCards;
	OurStats statMap;

	int totalrolls = 10000;
	cout << "Rolling " << totalrolls << " times, then calculating." << endl;
	for (int ctr = 0; ctr < totalrolls; ctr++)
	{
		theDice.roll();
		if (theDice.gotTripleDoubles())
		{
			theDice.clearDoubles();
			ourLocation.goToJail();
		} else
		{
			ourLocation.moveLocation(theDice.rollResult());
		}

		statMap.landedAt(ourLocation.getCurrentLocation());
	}

	statMap.reportTotals(theDice.numTimesRolled());

	return 0;
}
