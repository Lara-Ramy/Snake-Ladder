#pragma once

#include "Card.h"

// [ CardSeven ] Summary:
// Its Apply() Function: Decrements the value of the passing player’s wallet by a value
// Its Parameters: The Wallet Value to decrease --> put it as a "data member" and read it in ReadCardParameters()

class CardSeven :	public Card
{

public:
	CardSeven(const CellPosition & pos); // A Constructor takes card position

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of CardSeven on the passed Player
	                                                  // by restarting the game for the player in front of me

	//virtual void Save(ofstream& OutFile, int num) = 0;	// Saves the GameObject parameters to the file
	//virtual void Load(ifstream& Infile, Grid* pGrid) = 0;	// Loads and Reads the GameObject parameters from the file

	virtual ~CardSeven(); // A Virtual Destructor
};

