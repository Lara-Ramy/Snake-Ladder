#include "CardSix.h"

CardSix::CardSix(const CellPosition & pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 6; // set the inherited cardNumber data member with the card number (6 here)
}

CardSix::~CardSix(void)
{
}

void CardSix::ReadCardParameters(Grid * pGrid)
{
	
	
	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) (numbered below) to implement this function ==


	// 1- Get a Pointer to the Input / Output Interfaces from the Grid
Input* pI;
Output* pO;
pI=pGrid->GetInput();
pO=pGrid->GetOutput();
	// 2- Read a cell clicked by the user using the Input class
	//    Don't forget to first print to a descriptive message to the user like:"New CardSix: enter the needed cell position"
	pO->PrintMessage("New CardSix: click on the needed cell position");
CellPosition sixpos= pI->GetCellClicked();

	// [ Note ]:
	// In CardSix, the only parameter of CardSix is the "pos" value
	// Card parameters are the inputs you need to take from the user in the time of adding the Card in the grid
	// to be able to perform his Apply() action

	// 3- Clear the status bar
pO->ClearStatusBar();

}
void CardSix::Apply(Grid* pGrid, Player* pPlayer)
{
		
	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below
	

	// == Here are some guideline steps (numbered below) (numbered below) to implement this function ==

	// 1- Call Apply() of the base class Card to print the message that you reached this card number
Card* Card6Apply;
	Card6Apply->SetCardNumber(6);
	Card6Apply->Apply(pGrid, pPlayer);
	// 2- move the player to the req cell
pGrid->UpdatePlayerCell(pPlayer, sixpos);
	// 3-check for game objects and apply
Ladder* lad;
Snake* Sn;
Card* Ca;
int CellN=sixpos.GetCellNumFromPosition(sixpos);
CellPosition ladpos=lad->GetPosition();
int ladN=ladpos.GetCellNumFromPosition(ladpos);
CellPosition Snpos=Sn->GetPosition();
int SnN=Snpos.GetCellNumFromPosition(Snpos);
CellPosition Capos=Ca->GetPosition();
int CaN=Capos.GetCellNumFromPosition(Capos);
if(ladN==CellN)
lad->Apply(pGrid, pPlayer);
if(SnN==CellN)
Sn->Apply(pGrid, pPlayer);
if(CaN==CellN)
Ca->Apply(pGrid, pPlayer);
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
