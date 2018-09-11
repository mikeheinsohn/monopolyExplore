#include <iostream>
#include <iomanip>
#include <map>
#include "OurStats.h"
#include "board.h"
#include "globals.h"

OurStats::OurStats()
{
	for (int idx = 0; idx < BOARDSIZE; ++idx)
	{
		statMap[idx] = 0;
	}
}


OurStats::~OurStats()
{
	// ctor
}


void OurStats::landedAt(int location)
{
	statMap.at(location)++;
}


void OurStats::reportTotals(int totalRolls)
{
	// Reverse the map so it's sorted
	for (auto &idx : statMap)
	{
		sortedMap.insert(std::pair<int, int>(idx.second, idx.first));
	}

	// Tell about where we landed
	Board tempBoard;
	for (auto &idx : sortedMap)
	{
		std::cout << "Landed " << static_cast<double>(idx.first) / static_cast<double>(totalRolls) * 100.0 << 
			" % on " << tempBoard.getNameAtLocation(idx.second) << std::endl;
	}
}