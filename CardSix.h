#pragma once

#include "Card.h"
#include "cell.h"
#include "Ladder.h"
#include "Snake.h"
// [ CardSix ] Summary:
// Its Apply() Function: move to a specific cell
// Its Parameters: cell to move to and read it in ReadCardParameters()

class CardSix :	public Card
{
	// CardSix Parameters:
	CellPosition sixpos; // the cell to move to

public:
	CardSix(const CellPosition & pos); // A Constructor takes card position

	virtual void ReadCardParameters(Grid * pGrid); // Reads the parameters of CardSix which is: sixpos

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of CardSix on the passed Player
	                                                  // by moving to a specific cell
	
	//virtual void Save(ofstream& OutFile, int num) = 0;	// Saves the GameObject parameters to the file
	//virtual void Load(ifstream& Infile, Grid* pGrid) = 0;	// Loads and Reads the GameObject parameters from the file

	virtual ~CardSix(); // A Virtual Destructor
};
