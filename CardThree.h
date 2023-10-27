#include"Card.h"
#include"RollDiceAction.h"
class CardThree:public Card
{

public:
	CardThree(const CellPosition & pos ); //constructor takes card position
	
	virtual void ReadCardParameters(Grid * pGrid);

	virtual void Apply(Grid* pGrid, Player* pPlayer);  // Applies the effect of CardThree on the passed Player
	                                                  // by giving the same player an extra dice roll

	virtual ~CardThree();  //virtual destructor

	//virtual void Save(ofstream& OutFile, int num) = 0;	// Saves the GameObject parameters to the file
	//virtual void Load(ifstream& Infile, Grid* pGrid) = 0;	// Loads and Reads the GameObject parameters from the file

};