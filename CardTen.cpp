#include "CardTen.h"

CardTen::CardTen(const CellPosition& position) : Card(position) // set the cell position of the card
{
	cardNumber = 9; // set the inherited cardNumber data member with the 9
	cardPrice = 0;  // initializing cardPrice & fees
	fees = 0;
}
CardTen::~CardTen() {}

void CardTen::ReadCardParameters(Grid* pGrid) {
	if (number == 0) {
		// 1- Get a Pointer to the Input / Output Interfaces from the Grid
		Input* pIn = pGrid->GetInput();
		Output* pOut = pGrid->GetOutput();
		// 2- Read an Integer from the user using the Input class and set the cardprice & fees parameter with it in the design mode
		pOut->PrintMessage("CardTen: Please enter cardPrice...");
		cardPrice = pIn->GetInteger(pOut);

		pOut->PrintMessage("CardTen: Please enter fees...");
		fees = pIn->GetInteger(pOut);

		// 3 - validation checks
		while (cardPrice <= 0) {
			pGrid->PrintErrorMessage("Please enter a value lareder that 0, click to re-enter...");
			pOut->PrintMessage("CardTen: Please enter cardPrice...");
			cardPrice = pIn->GetInteger(pOut);
		}

		while (fees <= 0) {
			pGrid->PrintErrorMessage("Please enter a value larger that 0, click to re-enter...");
			pOut->PrintMessage("CardTen: Please enter fees...");
			fees = pIn->GetInteger(pOut);
		}

		// 4- Clear the status bar
		pOut->ClearStatusBar();
	}
	number++;
}

void CardTen::Apply(Grid* pGrid, Player* pPlayer) {
	// 1- Call Apply() of the base class Card to print the message that you reached this card number
	Card* Card10Apply;
	Card10Apply->SetCardNumber(10);
	Card10Apply->Apply(pGrid, pPlayer);

	// 2 - call the output and input classes to print messages and take input
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	// 3 - if the card is not bought, ask the player if he/she wats to buy it.
	if (isBought == 0) {
		if (pPlayer->GetWallet() >= cardPrice) {
			pOut->PrintMessage("Do you want to buy CardTen? y/n");
			string ans = pIn->GetSrting(pOut);
			pOut->ClearStatusBar();

			while (ans != "y" || ans != "n") {
				pGrid->PrintErrorMessage("Please enter y/n");
				ans = pIn->GetSrting(pOut);
				pOut->ClearStatusBar();
			}
			if (ans == "n") {
				return;
			}
			if (ans == "y") {
				pPlayer->SetWallet(pPlayer->GetWallet() - cardPrice);
				isBought = 1;
				owner = pGrid->GetCurrentPlayer();
				return;
			}
		}
	}

	// 4 - if the city is bought, decrese the wallet of other players and increase the owners wallet
	if (isBought == 1) {
		if (pGrid->GetCurrentPlayer() == owner) {
			return;
		}
		else {
			pPlayer->SetWallet(pPlayer->GetWallet() - fees);
			owner->SetWallet(owner->GetWallet() + fees);
		}
	}

}

void CardTen::setOwner(Player* p) {
	owner = p;
}

int CardTen::getCardPrice() {
	return cardPrice;
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
