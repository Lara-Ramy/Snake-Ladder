#include "CardSeven.h"

CardSeven::CardSeven(const CellPosition & pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 7; // set the inherited cardNumber data member with the card number (7 here)
}

CardSeven::~CardSeven(void)
{
}


void CardSeven::Apply(Grid* pGrid, Player* pPlayer)
{
		
	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below
	

	// == Here are some guideline steps (numbered below) (numbered below) to implement this function ==

	// 1- Call Apply() of the base class Card to print the message that you reached this card number

	Card* Card7Apply;
	Card7Apply->SetCardNumber(7);
	Card7Apply->Apply(pGrid, pPlayer);

	// 2- get current player's cell num

	Cell* pCell=pPlayer->GetCell();                
	CellPosition CurrentPosition = pCell->GetCellPosition();
	int CurrentNum= CurrentPosition.GetCellNum();
	int Curr_Pnum=pGrid-> GetcurrPlayerNumber();
	int min=1000;
	Player* Nxt_Player;
	// 3- get next player pos

	for (int i=0;i < MaxPlayerCount;i++) 
	{
		pGrid->SetcurrPlayerNumber(i);
		Player* Player_i = pGrid->GetCurrentPlayer();
		Cell* pCell_i=Player_i->GetCell();                
		CellPosition CurrentPosition_i = pCell_i->GetCellPosition();
		int CurrentNum_i= CurrentPosition_i.GetCellNum();
			if(CurrentNum_i>CurrentNum && CurrentNum_i<min){
				min=CurrentNum_i;
				Nxt_Player=Player_i;
		}		
	}
	//4- update position to start
	CellPosition start(1);
	pGrid->UpdatePlayerCell(Nxt_Player,  start);	
	
	//5- return pointer to original player
	
	pGrid->SetcurrPlayerNumber(Curr_Pnum);
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
