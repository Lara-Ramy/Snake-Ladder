#include"InputDiceValueAction.h"

#include"Grid.h"
#include"Player.h"

InputDiceValueAction::InputDiceValueAction(ApplicationManager* pAppManager ):Action(pAppManager)
{ 

}

void InputDiceValueAction::ReadActionParameters()
{
	// Get a Pointer to the Input / Output Interfaces
	Grid* pGrid=pManager->GetGrid();
	Output* pOut=pGrid->GetOutput();
	Input* pIn=pGrid->GetInput();  

	// Read the inputdicevalue parameter

	pOut->PrintMessage("please enter a dice value between 1-6");
	inputdicevalue=pIn->GetInteger(pOut); 
	if(inputdicevalue<1 || inputdicevalue>6  )
		pGrid->PrintErrorMessage("Error: Dice value not between 1-6 ! Click to continue ...");
	
	// Clear messages
	pOut->ClearStatusBar();

}

void InputDiceValueAction:: Execute()
{

ReadActionParameters();

if(pManager->GetGrid()->GetEndGame()==0 )   //Game has not ended
{
Grid*pgrid=pManager->GetGrid();  
 
Player* currplayer=pgrid->GetCurrentPlayer(); //Get the "current" player from pGrid

currplayer->Move(pgrid,inputdicevalue);  	// Move the currentPlayer using function Move of class player

pgrid->AdvanceCurrentPlayer();            // Advance the current player number of pGrid

}

else
	return;      //Game has ended so dice will not be rolled

}

InputDiceValueAction::~InputDiceValueAction ()
{

}