#include "CardTwo.h"

CardTwo::CardTwo(const CellPosition & pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 2; // set the inherited cardNumber data member with the card number (2 here)
}

CardTwo::~CardTwo(void)
{
}


void CardTwo::Apply(Grid* pGrid, Player* pPlayer)
{
		
	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below
	

	// == Here are some guideline steps (numbered below) (numbered below) to implement this function ==

	// 1- Call Apply() of the base class Card to print the message that you reached this card number
Card* Card2Apply;
	Card2Apply->SetCardNumber(2);
	Card2Apply->Apply(pGrid, pPlayer);
	// 2- move the player to the next ladder then take it
Ladder* lad;
Cell* pCell=pPlayer->GetCell();                
CellPosition CurrentPosition = pCell->GetCellPosition(); 
lad=pGrid->GetNextLadder(CurrentPosition);
if (lad==NULL){
return;
}
else{
CellPosition ladpos=lad->GetPosition();
pGrid->UpdatePlayerCell(pPlayer, ladpos);
lad->Apply(pGrid, pPlayer);
}
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
