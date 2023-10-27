#include "SwitchToPlayMode.h"


SwitchToPlayMode::SwitchToPlayMode(ApplicationManager* pApp) : Action(pApp)
{
}

void SwitchToPlayMode::ReadActionParameters()
{
}

void SwitchToPlayMode::Execute()
{
	Grid* pGrid = pManager->GetGrid();

	Input* pIn = pGrid->GetInput();

	Output* pOut = pGrid->GetOutput();

	pGrid->UpdateInterface();

	CellPosition pos;

	pos.SetHCell(0);

	pos.SetVCell(8);


	pOut->PrintMessage("Do you want to save the grid? (Y/N) ");
	string ans = pIn->GetSrting(pOut);
	if ((ans == "Y" || ans == "y"))
	{
		for (int i = 0; i < 4; i++)
		{
			Player* player = pGrid->GetCurrentPlayer();

			player->SetWallet(100);

			player->Setturncount(0);

			pGrid->AdvanceCurrentPlayer();

			pGrid->UpdatePlayerCell(player, pos);
		}

		pOut->ClearStatusBar();

		pOut->CreatePlayModeToolBar();

		pGrid->SetEndGame(false);
	}

	else
	{
		for (int j = 0; j < 99; j++)
		{

			pGrid->RemoveObjectFromCell(pos.GetCellPositionFromNum(j));

		}

		pOut->ClearStatusBar();

		pOut->CreateDesignModeToolBar();

		return;
	}
}

SwitchToPlayMode::~SwitchToPlayMode()
{
}