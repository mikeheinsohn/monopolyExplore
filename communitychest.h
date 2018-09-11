#pragma once
#include <map>
#include <string>

class CommunityChest
{
public:
	CommunityChest();
	~CommunityChest();
	int checkCommunityChestCard();
	std::string getName(int);
	void nextCommunityChestCard();

private:
	static int cardSlot;
	int totalCards();
	std::map<int, int> communityChestCards;

};
