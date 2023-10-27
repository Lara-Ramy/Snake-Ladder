#include "SaveGridAction.h"
#include <fstream>
#include "Input.h"
#include "Output.h"
#include "Grid.h"

SaveGridAction::SaveGridAction(ApplicationManager* pApp) : Action(pApp)
{
}

SaveGridAction::~SaveGridAction()
{
}

void SaveGridAction::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();

	Output* pOut = pGrid->GetOutput();
	
	Input* pIn = pGrid->GetInput();

	
	pOut->PrintMessage("Saving Grid Action : Enter Filename (e.g. myFile.txt)...");
	
	fileName = pIn->GetSrting(pOut);

	pOut->ClearStatusBar();
}


void SaveGridAction::Execute()
{	
	ReadActionParameters();

	Grid* pGrid = pManager->GetGrid();
	
	//pGrid->GameObjectSave(fileName);
}
