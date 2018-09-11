#include <iostream>
#include <iomanip>
#include "location.h"
#include "globals.h"
#include "board.h"
#include "chance.h"
#include "communitychest.h"

Location::Location()
{
	currentLocation = 0;
}


Location::~Location()
{
	// dtor, nothing for now
}


bool Location::landedOnChance()
{
	// chance 7, 22, 36
	if (currentLocation == 7 || currentLocation == 22 || currentLocation == 36)
	{
		return true;
	}
	else
	{
		return false;
	}
}


bool Location::landedOnCommunityChest()
{
	// community chest 2, 17, 33
	if (currentLocation == 2 || currentLocation == 17 || currentLocation == 33)
	{
		return true;
	}
	else
	{
		return false;
	}
}


int Location::getCurrentLocation()
{
	return currentLocation;
}


void Location::advanceToRailroad()
{
	// Move to the nearest railroad.
	// chance 7, 22, 36
	// rr's are 5, 15, 25, 35
	// Only chance cards move to railroads, so use fixed logic.
	if (currentLocation == 7) // chance 1
	{
		currentLocation = 15; // Pennsylvania Railroad
	}
	else if (currentLocation == 22) // chance 2
	{
		currentLocation = 25; // B&O Railroad
	}
	else if (currentLocation == 36) // chance 3
	{
		currentLocation = 5; // Reading Railroad
	}
	
}


void Location::advanceToUtility()
{
	// Move to the nearest utility. For now hardcode to Water Works.
	// chance 7, 22, 36
	// utility 12, 28
	// Only chance cards move to utilities, so use fixed logic.
	if (currentLocation == 7 || currentLocation == 36) // chance 1 or 3
	{
		currentLocation = 12; // Electric Company
	}
	else if (currentLocation == 22) // chance 2
	{
		currentLocation = 28; // Water Works
	}
}


void Location::goToGo()
{
	// Pretty simple, move to Go.
	currentLocation = 0;
}


void Location::goToJail()
{
	// In the Clink!
	currentLocation = 10;
}


void Location::moveLocation(int numSpaces)
{
	// Generally we move a certain number of spaces forward, but there are rules
	// Moving past the end of the Location swaps around to Go
	// Special cases for the globals - back 3, nearest railroad, nearest utility, and of course nomove

	currentLocation = (currentLocation + numSpaces) % BOARDSIZE;

	// Did we land on Chance or Community Chest? Handle it
	// check chance first, as the -3 card may land us on community chest for another move
	if (landedOnChance())
	{
		Chance tempChance;
		int newLoc = tempChance.checkChanceCard();
		tempChance.nextChanceCard();
		if (newLoc == NOMOVE)
		{
			// do nothing
		}
		else if (newLoc == BACKTHREE)
		{
			currentLocation -= 3; // Safe because Chance cards are all more than 3 from start
		}
		else if (newLoc == RAILROAD)
		{
			advanceToRailroad();
		}
		else if (newLoc == UTILITY)
		{
			advanceToUtility();
		}
		else
		{
			currentLocation = newLoc;
		}

	}


	if (landedOnCommunityChest())
	{
		CommunityChest tempCommunityChest;
		int newLoc = tempCommunityChest.checkCommunityChestCard();
		tempCommunityChest.nextCommunityChestCard();
		if (newLoc == NOMOVE)
		{
			// do nothing
		}
		else
		{
			currentLocation = newLoc;
		}
	}

}
