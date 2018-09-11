#include <iostream>
#include "board.h"
#include "globals.h"

using namespace std;

Board::Board()
{
	boardMap[0] = "Go";
	boardMap[1] = "Mediterranean Avenue";
	boardMap[2] = "Community Chest 1";
	boardMap[3] = "Baltic Avenue";
	boardMap[4] = "Income Tax";
	boardMap[5] = "Reading Railroad";
	boardMap[6] = "Oriental Avenue";
	boardMap[7] = "Chance 1";
	boardMap[8] = "Vermont Avenue";
	boardMap[9] = "Connecticut Avenue";
	boardMap[10] = "In Jail / Just Visiting";
	boardMap[11] = "St. Charles Place";
	boardMap[12] = "Electric Company";
	boardMap[13] = "States Avenue";
	boardMap[14] = "Virginia Avenue";
	boardMap[15] = "Pennsylvania Railroad";
	boardMap[16] = "St. James Place";
	boardMap[17] = "Community Chest 2";
	boardMap[18] = "Tennessee Avenue";
	boardMap[19] = "New York Avenue";
	boardMap[20] = "Free Parking";
	boardMap[21] = "Kentucky Avenue";
	boardMap[22] = "Chance 2";
	boardMap[23] = "Indiana Avenue";
	boardMap[24] = "Illinois Avenue";
	boardMap[25] = "B & O Railroad";
	boardMap[26] = "Atlantic Avenue";
	boardMap[27] = "Ventnor Avenue";
	boardMap[28] = "Water Works";
	boardMap[29] = "Marvin Gardens";
	boardMap[30] = "Go To Jail";
	boardMap[31] = "Pacific Avenue";
	boardMap[32] = "North Carolina Avenue";
	boardMap[33] = "Community Chest 3";
	boardMap[34] = "Pennsylvania Avenue";
	boardMap[35] = "Short Line";
	boardMap[36] = "Chance 3";
	boardMap[37] = "Park Place";
	boardMap[38] = "Luxury Tax";
	boardMap[39] = "Boardwalk";
}


Board::~Board()
{
	// Nothing now
}


int Board::getLocationFromName(string theName)
{
	// Given a name, return the location, error code if not found.
	int key = NOTFOUND;
	for (auto &idx : boardMap)
	{
		if (idx.second == theName)
		{
			key = idx.first;
			break;
		}
	}
	return key;
}


string Board::getNameAtLocation(int slot)
{
	// Handle special cases
	if (slot == BACKTHREE)
	{
		return "Back Three Spaces";
	}
	else if (slot == NOMOVE)
	{
		return "Do not move";
	}
	else if (slot == RAILROAD)
	{
		return "Advance to nearest railroad";
	}
	else if (slot == UTILITY)
	{
		return "Advance to nearest utility";
	}
	else if (slot == NOTFOUND)
	{
		return "UNKNOWN";	
	} else
	{
		return boardMap.at(slot);
	}
}
