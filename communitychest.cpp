#include "communitychest.h"
#include "board.h"
#include "globals.h"
#include <string>
using namespace std;

// Cardslot is static, have to set its value here
int CommunityChest::cardSlot = 0;

CommunityChest::CommunityChest()
{
	Board tempBoard;

	communityChestCards[0] = tempBoard.getLocationFromName("Go");
	communityChestCards[1] = NOMOVE; // bank error
	communityChestCards[2] = NOMOVE; // doctor's fees
	communityChestCards[3] = NOMOVE; // sale of stock
	communityChestCards[4] = NOMOVE; // get out of jail free
	communityChestCards[5] = tempBoard.getLocationFromName("Go To Jail");
	communityChestCards[6] = NOMOVE; // grand opera night
	communityChestCards[7] = NOMOVE; // christmas fund matures
	communityChestCards[8] = NOMOVE; // income tax refund
	communityChestCards[9] = NOMOVE; // birthday
	communityChestCards[10] = NOMOVE; // life insurance
	communityChestCards[11] = NOMOVE; // hospital fees
	communityChestCards[12] = NOMOVE; // school fees
	communityChestCards[13] = NOMOVE; // consultancy fee
	communityChestCards[14] = NOMOVE; // street repairs
	communityChestCards[15] = NOMOVE; // second prize
	communityChestCards[16] = NOMOVE; // inherit $100
}


CommunityChest::~CommunityChest()
{
	// dtor - nothing for now
}


int CommunityChest::checkCommunityChestCard()
{
	// Check what the card does
	return communityChestCards.at(cardSlot);
}


string CommunityChest::getName(int slot)
{
	Board tempBoard;
	return tempBoard.getNameAtLocation(slot);
}


void CommunityChest::nextCommunityChestCard()
{
	// Point to the next card
	cardSlot++;
	if (cardSlot >= totalCards())
	{
		cardSlot = 0;
	}
}


// Private functions below
int CommunityChest::totalCards()
{
	return communityChestCards.size();
}
