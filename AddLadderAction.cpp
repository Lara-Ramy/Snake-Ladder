#include "AddLadderAction.h"

#include "Input.h"
#include "Output.h"
#include "Ladder.h"

AddLadderAction::AddLadderAction(ApplicationManager *pApp) : Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer
}

AddLadderAction::~AddLadderAction()
{
}

void AddLadderAction::ReadActionParameters() 
{	
	// Get a Pointer to the Input / Output Interfaces
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	// Read the startPos parameter
	pOut->PrintMessage("New Ladder: Click on its Start Cell ...");
	startPos = pIn->GetCellClicked();

	// Read the endPos parameter
	pOut->PrintMessage("New Ladder: Click on its End Cell ...");
	endPos = pIn->GetCellClicked();

    

	///TODO: Make the needed validations on the read parameters

	

	// Clear messages
	pOut->ClearStatusBar();
}


// Execute the action
void AddLadderAction::Execute()
{
	// The first line of any Action Execution is to read its parameter first 
	// and hence initializes its data members
	ReadActionParameters();

	// Create a Ladder object with the parameters read from the user
	Ladder* pLadder = new Ladder(startPos, endPos);

	Grid* pGrid = pManager->GetGrid(); // We get a pointer to the Grid from the ApplicationManager

	//Validation
	if (startPos.GetCellNum() == endPos.GetCellNum())
	{
		pGrid->PrintErrorMessage("Error !! Ladder's Start Cell Can not be the Same as its End cell ! Click to continue...");

		return;
	}

	if (startPos.HCell() != endPos.HCell())
	{
		pGrid->PrintErrorMessage("Error !! Ladder's Start Cell and End Cell Must be in the Same Column! Click to continue...");

		return;
	}

	if (startPos.VCell() < endPos.VCell())
	{
		pGrid->PrintErrorMessage("Error !! Ladder's Start Cell Must be below its End cell ! Click to continue...");

		return;
	}


	bool Laddersoverlapping = pGrid->IsOverlapping(pLadder);

	if (Laddersoverlapping)
	{
		pGrid->PrintErrorMessage("Error !! 2 ladders Can't overlap ! Click to continue ...");

		return;
	}

	if (startPos.VCell() == -1 || endPos.VCell() == -1)
	{
		pGrid->PrintErrorMessage("Error !! Choose Cells Below Toolbar ! Click to continue ...");

		return;
	}

	bool StartIsEnd = pGrid->CompareLadderSnake(endPos);

	if (StartIsEnd)
	{
		pGrid->PrintErrorMessage("Error !! Ladder's End cell can't be another ladder's or Snake's start ! Click to continue ...");

		return;
	}


	// Add the card object to the GameObject of its Cell:
	bool added = pGrid->AddObjectToCell(pLadder);

	// if the GameObject cannot be added
	if (!added)
	{
		// Print an appropriate message
		pGrid->PrintErrorMessage("Error !! Cell already has an object ! Click to continue ...");
	}
	// Here, the ladder is created and added to the GameObject of its Cell, so we finished executing the AddLadderAction

}
