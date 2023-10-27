#include "AddSnakeAction.h"

#include "Input.h"
#include "Output.h"
#include "Snake.h"
#include"Grid.h"

AddSnakeAction::AddSnakeAction(ApplicationManager* pApp) : Action(pApp)
{
}

AddSnakeAction::~AddSnakeAction()
{
}

void AddSnakeAction::ReadActionParameters()
{

	Grid* pGrid = pManager->GetGrid();

	Output* pOut = pGrid->GetOutput();

	Input* pIn = pGrid->GetInput();


	pOut->PrintMessage("New Snake: Click on its Start Cell ...");

	startPos = pIn->GetCellClicked();


	pOut->PrintMessage("New Snake: Click on its End Cell ...");

	endPos = pIn->GetCellClicked();


	pOut->ClearStatusBar();
}


void AddSnakeAction::Execute()
{
	ReadActionParameters();

	Snake* pSnake = new Snake(startPos, endPos);
	
	Grid* pGrid = pManager->GetGrid();


	if (startPos.GetCellNum() == endPos.GetCellNum())
	{
		pGrid->PrintErrorMessage("Error !! Snake's Start Cell Can not be the Same as its End cell ! Click to continue...");

		return;
	}

	if (startPos.HCell() != endPos.HCell())
	{
		pGrid->PrintErrorMessage("Error !! Snake's Start Cell and End Cell Must be in the Same Column! Click to continue...");

		return;
	}
	
	if (startPos.VCell() > endPos.VCell())
	{
		pGrid->PrintErrorMessage("Error !! Snake's Start Cell Must be Above its End cell ! Click to continue...");

		return;
	}

	
	bool Snakesoverlapping = pGrid->IsOverlapping(pSnake);

	if (Snakesoverlapping)
	{
		pGrid->PrintErrorMessage("Error !! 2 Snakes Can't overlap ! Click to continue ...");
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
		pGrid->PrintErrorMessage("Error !! End cell cannot be the start of another Ladder or Snake ! Click to continue ...");

		return;
	}
	
	
	bool added = pGrid->AddObjectToCell(pSnake);

	if (!added)
	{
		pGrid->PrintErrorMessage("Error !! Cell already has an object ! Click to continue ...");
	}

}
