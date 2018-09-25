#include "chance.h"
#include "board.h"
#include "globals.h"

// Cardslot is static, have to set its value here
int Chance::cardSlot = 0;

Chance::Chance()
{
	Board tempBoard;
	
	chanceCards[0] = GO;
	chanceCards[1] = ILLINOIS_AVENUE;
	chanceCards[2] = ST_CHARLES_PLACE;
	chanceCards[3] = UTILITY;
	chanceCards[4] = RAILROAD;
	chanceCards[5] = NOMOVE; // dividend of $50
	chanceCards[6] = NOMOVE; // get out of jail free
	chanceCards[7] = BACKTHREE;
	chanceCards[8] = JAIL;
	chanceCards[9] = NOMOVE; // general repairs
	chanceCards[10] = NOMOVE; // poor tax
	chanceCards[11] = READING_RAILROAD;
	chanceCards[12] = BOARDWALK;
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


std::string Chance::getName(int slot)
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
