#pragma once
#include <map>
#include <string>

class Location
{
public:
	Location();
	~Location();
	bool landedOnChance();
	bool landedOnCommunityChest();
	int getCurrentLocation();
	void advanceToRailroad();
	void advanceToUtility();
	void goToGo();
	void goToJail();
	void moveLocation(int);

private:
	int currentLocation;

};
