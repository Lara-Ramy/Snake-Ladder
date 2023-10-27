#include"Card.h"

class CardFour:public Card
{


public:
	CardFour(const CellPosition & pos);

	virtual void ReadCardParameters(Grid * pGrid); 

	virtual void Apply(Grid* pGrid, Player* pPlayer);
	
	//virtual void Save(ofstream& OutFile, int num);	// Saves the GameObject parameters to the file

	//virtual void Load(ifstream& InFile, Grid* pGrid);

	virtual ~CardFour(); 





};