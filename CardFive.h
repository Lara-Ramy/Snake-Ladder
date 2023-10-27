#pragma once

#include "Card.h"

// [ CardFive ] Summary:
// Its Apply() Function: moves backward the same amount of rolled dice

class CardFive :	public Card
{

public:
	CardFive(const CellPosition & pos); // A Constructor takes card position


	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of CardFive on the passed Player
	                                                  // by moving backward the same amount of rolled dice
	//virtual void Save(ofstream& OutFile, int num) = 0;	// Saves the GameObject parameters to the file
	//virtual void Load(ifstream& Infile, Grid* pGrid) = 0;	// Loads and Reads the GameObject parameters from the file

	virtual ~CardFive(); // A Virtual Destructor
};

