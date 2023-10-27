#include "CopyCard.h"
#include "Input.h"
#include "Output.h"
#include "CardOne.h"
#include "CardTwo.h"
#include "CardThree.h"
#include "CardFour.h"
#include "CardFive.h"
#include "CardSix.h"
#include "CardSeven.h"
#include "CardEight.h"
#include "CardNine.h"
#include "CardTen.h"
#include "CardEleven.h"
//#include "CardTwelve.h"
CopyCard::CopyCard(ApplicationManager* pApp) : Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer
}

CopyCard::~CopyCard()
{
}

void CopyCard::ReadActionParameters()
{

	// 1- Get a Pointer to the Input / Output Interfaces / CellPosition
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	CellPosition* pCell;

	// 2- Read the "cardPosition" parameter and set its data member
	pOut->PrintMessage("Copy Card: Please click on the card to be copied");
	cardPosition = pIn->GetCellClicked();
	
	// 3 - Read the "cardNumber" parameter and set its data member
	cardNumber = pIn->GetInteger(pOut);

	// 4 - Make the needed validations on the read parameters
	if (cardPosition.GetCellNum() == 1 || cardPosition.GetCellNum() == 99) {
		cardPosition.SetHCell(-1);
		cardPosition.SetVCell(-1);
	}

	// 5- Clear status bar
	pOut->ClearStatusBar();
}

void CopyCard::Execute()
{
	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) to implement this function ==

	// 1- The first line of any Action Execution is to read its parameter first
	ReadActionParameters();

	//2 - We get a pointer to the Grid from the ApplicationManager
	Grid* pGrid = pManager->GetGrid();

	//3 - We create a card object to be passed to the setClipboard function
	Card* pCard = NULL;
	switch (cardNumber)
	{
	case 1:
		pCard = new CardOne(cardPosition);
		break;
	case 2:
		pCard = new CardTwo(cardPosition);
		break;
	case 3:
		pCard = new CardThree(cardPosition);
		break;
	case 4:
		//pCard = new CardFour(cardPosition);
		break;
	case 5:
		pCard = new CardFive(cardPosition);
		break;
	case 6:
		pCard = new CardSix(cardPosition);
		break;
	case 7:
		pCard = new CardSeven(cardPosition);
		break;
	case 8:
		pCard = new CardEight(cardPosition);
		break;
	case 9:
		pCard = new CardNine(cardPosition);
		break;
	case 10:
		pCard = new CardTen(cardPosition);
		break;
	case 11:
		pCard = new CardEleven(cardPosition);
		break;
	//case 12:
		//pCard = new CardTwelve(cardPosition);
		//break;
		// A- Add the remaining cases
	}
	//4 - We use the setClipboard function to save the desired card
	pGrid->SetClipboard(pCard);
	delete pCard;
	// Here, the card is copied and saved to the clipboard in the grid class
	return;
}
