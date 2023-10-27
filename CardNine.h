#pragma once
#include "Card.h"
class CardNine : public Card
{
	int cardPrice;
	int fees;
	int number;
	bool isBought;
	Player* owner;

public:
	CardNine(const CellPosition& position);			//Nondefault constructor that takes cardPosition
	virtual ~CardNine();							//destructor
	
	virtual void ReadCardParameters(Grid* pGrid); // Reads the parameters of CardNine which is: Fees & cardPrice

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of CardNine on the passed Player
													  // by decrementing the player's wallet by the walletAmount data member
	void setOwner(Player* p);	// changes the owner

	int getCardPrice();	// returns the card price
	//virtual void Save(ofstream& OutFile, int num) = 0;	// Saves the GameObject parameters to the file
	//virtual void Load(ifstream& Infile, Grid* pGrid) = 0;	// Loads and Reads the GameObject parameters from the file

};

