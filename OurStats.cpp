#include <iostream>
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
	// dtor
}


void OurStats::landedAt(int location)
{
	statMap.at(location)++;
}


void OurStats::reportTotals(int totalRolls)
{
	// Reverse the map so it's sorted
	std::multimap<int, int> sortedMap;
	for (auto &idx : statMap)
	{
		sortedMap.insert(std::pair<int, int>(idx.second, idx.first));
	}


	// Tell about where we landed
	Board tempBoard;

	std::cout << std::endl << "Reporting on landing percentages, in absolute terms." << std::endl;
	for (auto idx = sortedMap.rbegin(); idx != sortedMap.rend(); ++idx)
	{
		double landedPercent = static_cast<double>(idx->first) / static_cast<double>(totalRolls) * 100.0;
		std::cout << "Landed " << landedPercent << " % on " << tempBoard.getNameAtLocation(idx->second) << std::endl;
	}

	std::cout << std::endl << "Reporting on landing percentages, relative to the most landed." << std::endl;
	double highestLanded = static_cast<double>((--sortedMap.end())->first);
	for (auto idx = sortedMap.rbegin(); idx != sortedMap.rend(); ++idx)
	{
		double landedPercent = static_cast<double>(idx->first) / highestLanded * 100.0;
		std::cout << "Landed " << landedPercent << " % on " << tempBoard.getNameAtLocation(idx->second) << std::endl;
	}

}
