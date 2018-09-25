#pragma once
#include <map>

// Here we will calculate various statistics about the game.
// Start with a frequency chart of each slot on the board.
class OurStats
{
public:
	OurStats();
	~OurStats();
	void landedAt(int);
	void reportTotals(int);

private:
	std::map<int, int> statMap;
};
