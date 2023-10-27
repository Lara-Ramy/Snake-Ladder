#pragma once

#include "Card.h"
#include "Ladder.h"
#include "Cell.h"

// [ CardTwo ] Summary:
// Its Apply() Function: move forward to the next ladder then take it

class CardTwo :	public Card
{

public:
	CardTwo(const CellPosition & pos); // A Constructor takes card position

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of CardTwo on the passed Player
	                                                  // by moving forward to the next ladder then taking it
	
	virtual ~CardTwo(); // A Virtual Destructor
	
	//virtual void Save(ofstream& OutFile, int num);	// Saves the GameObject parameters to the file
	//virtual void Load(ifstream& Infile, Grid* pGrid);	// Loads and Reads the GameObject parameters from the file

};

