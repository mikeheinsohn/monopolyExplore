#include "chance.h"
#include "board.h"
#include "globals.h"
using namespace std;

// Cardslot is static, have to set its value here
int Chance::cardSlot = 0;

Chance::Chance()
{
	Board tempBoard;
	
	chanceCards[0] = tempBoard.getLocationFromName("Go");
	chanceCards[1] = tempBoard.getLocationFromName("Illinois Avenue");
	chanceCards[2] = tempBoard.getLocationFromName("St. Charles Place");
	chanceCards[3] = UTILITY;
	chanceCards[4] = RAILROAD;
	chanceCards[5] = NOMOVE; // dividend of $50
	chanceCards[6] = NOMOVE; // get out of jail free
	chanceCards[7] = BACKTHREE;
	chanceCards[8] = tempBoard.getLocationFromName("In Jail / Just Visiting");
	chanceCards[9] = NOMOVE; // general repairs
	chanceCards[10] = NOMOVE; // poor tax
	chanceCards[11] = tempBoard.getLocationFromName("Reading Railroad");
	chanceCards[12] = tempBoard.getLocationFromName("Boardwalk");
	chanceCards[13] = NOMOVE; // elected chairman
	chanceCards[14] = NOMOVE; // building and loan matures
}


Chance::~Chance()
{
	// dtor - nothing for now
}


int Chance::checkChanceCard()
{
	// Check what the card does
	return chanceCards.at(cardSlot);
}


string Chance::getName(int slot)
{
	Board tempBoard;
	return tempBoard.getNameAtLocation(slot);
}


void Chance::nextChanceCard()
{
	// Point to the next card
	cardSlot++;
	if (cardSlot >= totalCards())
	{
		cardSlot = 0;
	}
}


// Private functions below
int Chance::totalCards()
{
	return chanceCards.size();
}
