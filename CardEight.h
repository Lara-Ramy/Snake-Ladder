#pragma once

#include "Card.h"

// [ CardEight ] Summary:
// Its Apply() Function: send player to prison
// Its Parameters: coins needed to get out of prison

class CardEight :	public Card
{
	// CardEight Parameters:
	int CoinsAmount; // coins needed to get out of prison

public:
	CardEight(const CellPosition & pos); // A Constructor takes card position

	virtual void ReadCardParameters(Grid* pGrid); // Reads the parameters of CardEight which is: CoinsAmount

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of CardEight on the passed Player
	                                                  // sending player to prison

	//virtual void Save(ofstream& OutFile, int num) = 0;	// Saves the GameObject parameters to the file
	//virtual void Load(ifstream& Infile, Grid* pGrid) = 0;	// Loads and Reads the GameObject parameters from the file

	virtual ~CardEight(); // A Virtual Destructor
};

