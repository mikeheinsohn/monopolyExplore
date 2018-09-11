#pragma once
#include <map>
#include <string>

class Chance
{
public:
	Chance();
	~Chance();
	int checkChanceCard();
	std::string getName(int);
	void nextChanceCard();

private:
	static int cardSlot;
	int totalCards();
	std::map<int, int> chanceCards;

};
