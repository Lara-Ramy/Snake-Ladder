#include "DeleteGameObjectAction.h"
#include "Input.h"
#include "Output.h"
#include "GameObject.h"
#include"Grid.h"


DeleteGameObjectAction::DeleteGameObjectAction(ApplicationManager* pApp) : Action(pApp)
{
}

DeleteGameObjectAction::~DeleteGameObjectAction(void)
{
}

void DeleteGameObjectAction::ReadActionParameters()
{	
}

void DeleteGameObjectAction::Execute()
{
	Grid* pGrid = pManager->GetGrid();

	Output* pOut = pGrid->GetOutput();

	Input* pIn = pGrid->GetInput();

	pOut->PrintMessage("Please, click on the object you want to delete !");
	CellPosition Posobj = pIn->GetCellClicked();

	
	pGrid->RemoveObjectFromCell(Posobj);
	

	pOut->ClearStatusBar();

}

