#include "SwitchToDesignMode.h"


SwitchToDesignMode::SwitchToDesignMode(ApplicationManager* pApp) : Action(pApp)
{
}


void SwitchToDesignMode::ReadActionParameters()
{
}


void SwitchToDesignMode::Execute()
{

	Grid* pGrid = pManager->GetGrid();
	Input* pIn = pGrid->GetInput();
	
	Output* pOut = pGrid->GetOutput();

	


	pOut->PrintMessage("Do you want to end the game (yes or NO)");
	string ans=pIn->GetSrting(pOut);
	
	if (ans == "yes" && pGrid->GetEndGame() == false)
	{
		pGrid->SetcurrPlayerNumber(0);

		Player* current = pGrid->GetCurrentPlayer();
		
		int r[4];

		for (int i = 0; i < 3; i++)
		{
		
			r[i] = current->GetWallet();
			
			pGrid->AdvanceCurrentPlayer();
			
			current = pGrid->GetCurrentPlayer();
		}

		int maximum = r[0];
		for (int i = 1; i < 3; i++)
		{
			if (maximum < r[i])
				maximum = r[i];
		}

		int CurrentPlayerNumber;
		for (int i = 0; i < 3; i++) 
		{
			if (maximum == r[i])
				CurrentPlayerNumber = i;
		}

		pOut->PrintMessage("Player" + to_string(CurrentPlayerNumber) + " is the winner with wallet value " + to_string(maximum) + ", click to continue");
		
		int x, y;

		pIn->GetPointClicked(x, y);
		
		pOut->ClearStatusBar();
		
		pOut->CreateDesignModeToolBar();
		
		UI.InterfaceMode = MODE_DESIGN;
		
		pGrid->UpdateInterface();

	}
	
	else if (ans=="yes" && pGrid->GetEndGame()==true)
	{
		pOut->PrintMessage("You are the winner");

		int x, y;
		pIn->GetPointClicked(x, y);

		pOut->ClearStatusBar();

		pOut->CreateDesignModeToolBar();

		UI.InterfaceMode = MODE_DESIGN;

		pGrid->UpdateInterface();
	}

	else
	{
		pOut->ClearStatusBar();

		pOut->CreateDesignModeToolBar();

		return;
	}	
}

SwitchToDesignMode::~SwitchToDesignMode()
{
}