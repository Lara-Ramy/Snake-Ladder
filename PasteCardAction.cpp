#include "PasteCardAction.h"
#include "Input.h"
#include "Output.h"
#include "Grid.h"
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
#include "CardTwelve.h"
PasteCardAction::PasteCardAction(ApplicationManager* pApp) : Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer
}

PasteCardAction::~PasteCardAction()
{
}

void PasteCardAction::ReadActionParameters()
{

	// 1- Get a Pointer to the Input / Output Interfaces / CellPosition
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	// 2- Read the "cardPosition" parameter and set its data member
	pOut->PrintMessage("Paste Card: Please click on the cell to place the cards");
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

void PasteCardAction::Execute()
{
	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) to implement this function ==

	// 1- The first line of any Action Execution is to read its parameter first
	ReadActionParameters();

	//2 - We get a pointer to the Grid from the ApplicationManager
	Grid* pGrid = pManager->GetGrid();

	//3 - We create a card pointer to get the card in the clipboard
	Card* pCard = pGrid->GetClipboard();
	
	
	if (!pGrid->GetClipboard())
	{
		pGrid->PrintErrorMessage("Error: Empty Clipboard");
		return;
	}

	//4 - We use the add object to cell function to save the desired card
	bool added = pGrid->AddObjectToCell(pCard);

	//5 - if the GameObject cannot be added in the Cell, Print the appropriate error message on statusbar
	if (!added) {
		pGrid->PrintErrorMessage("Error: Cell already has an object! Clich to continue ...");
	}
	delete pCard;

	// Here, the card is cut and saved to the clipboard in the grid class
	return;
}
