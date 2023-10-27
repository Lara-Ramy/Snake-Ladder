#include "CardEight.h"

CardEight::CardEight(const CellPosition & pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 8; // set the inherited cardNumber data member with the card number (8 here)
}

CardEight::~CardEight(void)
{
}

void CardEight::ReadCardParameters(Grid* pGrid)
{
	
	
	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) (numbered below) to implement this function ==


	// 1- Get a Pointer to the Input / Output Interfaces from the Grid
	Input* pI = pGrid -> GetInput();
	Output* pO = pGrid -> GetOutput();

	// 2- Read an Integer from the user using the Input class and set the walletAmount parameter with it
	//    Don't forget to first print to a descriptive message to the user like:"New CardEight: Enter its wallet amount ..."
	pO->PrintMessage("New CardEight: enter amount of coins needed to get out of prison");
CoinsAmount=pI->GetInteger(pO);

	// [ Note ]:
	// In CardEight, the only parameter of CardEight is the "CoinsAmount" value to decrease from player
	// Card parameters are the inputs you need to take from the user in the time of adding the Card in the grid
	// to be able to perform his Apply() action

	// 3- Clear the status bar
pO->ClearStatusBar();

}

void CardEight::Apply(Grid* pGrid, Player* pPlayer)
{
		
	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below
	

	// == Here are some guideline steps (numbered below) (numbered below) to implement this function ==

	// 1- Call Apply() of the base class Card to print the message that you reached this card number

	Card* Card8Apply;
	Card8Apply->SetCardNumber(8);
	Card8Apply->Apply(pGrid, pPlayer);

	// 2- decide whether to freeze or to pay

	Input* pI;
	Output* pO;
	pO = pGrid->GetOutput();
	pO->PrintMessage("enter 1 to pay with coins and 2 to freeze 3 rounds");
	int option=pI->GetInteger(pO);
	pO->ClearStatusBar();
	
	//3-pay with coins option
	
	if(option==1){
	int wallet=pPlayer->GetWallet();
	pPlayer->SetWallet(wallet-CoinsAmount);
	}

	//4-freeze option

	if(option==2){
	pPlayer->SetPrisoned(1);
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
