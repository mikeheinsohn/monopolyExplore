#pragma once
#include <map>
#include <string>

class Board
{
public:
	Board();
	~Board();
	int getLocationFromName(std::string);
	std::string getNameAtLocation(int);

private:
	std::map<int, std::string> boardMap;

};
