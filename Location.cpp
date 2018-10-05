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
	if (currentLocation == CHANCE1 || 
		currentLocation == CHANCE2 || 
		currentLocation == CHANCE3)
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
	if (currentLocation == COMMUNITYCHEST1 || 
		currentLocation == COMMUNITYCHEST2 || 
		currentLocation == COMMUNITYCHEST3)
	{
		return true;
	}
	else
	{
		return false;
	}
}


bool Location::landedonGoToJail()
{
	if (currentLocation == GOTOJAIL)
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
	// Only chance cards move to railroads, so use fixed logic.
	if (currentLocation == CHANCE1)
	{
		currentLocation = PENNSYLVANIA_RAILROAD;
	}
	else if (currentLocation == CHANCE2)
	{
		currentLocation = BO_RAILROAD;
	}
	else if (currentLocation == CHANCE3)
	{
		currentLocation = READING_RAILROAD;
	}
}


void Location::advanceToUtility()
{
	// Move to the nearest utility.
	// Only chance cards move to utilities, so use fixed logic.
	if (currentLocation == CHANCE1 || currentLocation == CHANCE3)
	{
		currentLocation = ELECTRIC_COMPANY;
	}
	else if (currentLocation == CHANCE2)
	{
		currentLocation = WATER_WORKS;
	}
}


void Location::goToGo()
{
	// Pretty simple, move to Go.
	currentLocation = GO;
}


void Location::goToJail()
{
	// In the Clink!
	currentLocation = JAIL;
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
	} // end handling Chance


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
	} // end handling Community Chest

	// Last check - did we land on Go To Jail?
	if (landedonGoToJail())
	{
		goToJail();
	}

}
