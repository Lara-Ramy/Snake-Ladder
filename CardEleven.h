#pragma once
#include "Card.h"
class CardEleven : public Card
{
	int cardPrice;
	int fees;
	int number;
	bool isBought;
	Player* owner;

public:
	CardEleven(const CellPosition& position);			//Nondefault constructor that takes cardPosition
	virtual ~CardEleven();							//destructor

	void ReadCardParameters(Grid* pGrid); // Reads the parameters of CardEleven which is: Fees & cardPrice

	void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of CardEleven on the passed Player
													  // by decrementing the player's wallet by the walletAmount data member
	void setOwner(Player* p);	// changes the owner

	//virtual void Save(ofstream& OutFile, int num) = 0;	// Saves the gameobj parameters
	//virtual void Load(ifstream& Infile, Grid* pGrid) = 0;	// Loads and Reads the GameObject parameters from the file


	int getCardPrice();	// returns the card price
};

