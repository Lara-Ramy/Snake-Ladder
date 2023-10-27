#include "OpenGridAction.h"
#include <fstream>
 // We need to include all header files
#include"Grid.h"
#include"Ladder.h"
#include "Snake.h"
#include "Card.h"

OpenGridAction::OpenGridAction(ApplicationManager* pApp) : Action(pApp)
{
}


void OpenGridAction::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();

	Output* pOut = pGrid->GetOutput();
	
	Input* pIn = pGrid->GetInput();


	pOut->PrintMessage("Please enter the file's name ...");
	

	fileName = pIn->GetSrting(pOut);


	pOut->ClearStatusBar();
}


void OpenGridAction::Execute()
{

	ReadActionParameters();


	Grid* pGrid = pManager->GetGrid();


	pGrid->ClearAllObjects();

	ifstream Object;

	Object.open(fileName + ".txt");


	if (!Object)
		return;

	pGrid->ClearAllObjects();

	int x;

	for (int Counter = 1; Counter < 5; Counter++)
	{
		Object >> x;

		for (int i = 0; i < x; i++)
		{
			if (Counter == 1)
			{
				Ladder* pLadder = new Ladder(0, 0);

				pLadder->Load(Object, pGrid);

				delete pLadder;
			}
			else if (Counter == 2){
				Snake* pSnake = new Snake(0, 0);

				pSnake->Load(Object, pGrid);

				delete pSnake;
			}

		}
	}
}

// adding switch cases and other conditions for cards

OpenGridAction::~OpenGridAction()
{
}
