#include "CardFive.h"

CardFive::CardFive(const CellPosition & pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 5; // set the inherited cardNumber data member with the card number (5 here)
}

CardFive::~CardFive(void)
{
}


void CardFive::Apply(Grid* pGrid, Player* pPlayer)
{
		
	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below
	

	// == Here are some guideline steps (numbered below) (numbered below) to implement this function ==

	// 1- Call Apply() of the base class Card to print the message that you reached this card number
Card* Card5Apply;
	Card5Apply->SetCardNumber(5);
	Card5Apply->Apply(pGrid, pPlayer);
	// 2- get rolled value and move
int RNum = pPlayer->GetJustRolledDiceNum();
pPlayer->Move(pGrid, (-RNum));
}

//void CardEight::Save(ofstream& OutFile, int num)
//{
//	if (num == 3)
//	{
		//OutFile << "5" << endl;
//	}
	// << position.GetCellNumFromPosition(position) << endl;

//}
//void CardEight::Load(ifstream& InFile, Grid* pGrid) {
	//Card* pC;
	//pC = new CardEight(position);
	//pGrid->AddObjectToCell(pC);
//}
