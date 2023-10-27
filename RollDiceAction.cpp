#include "RollDiceAction.h"

#include "Grid.h"
#include "Player.h"
#include"Cell.h"
#include"Card.h"

#include <time.h> // used to in srand to generate random numbers with different seed

RollDiceAction::RollDiceAction(ApplicationManager *pApp) : Action(pApp)
{
}

void RollDiceAction::ReadActionParameters()
{
	// no parameters to read from user
}

void RollDiceAction::Execute()
{

	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below

	// == Here are some guideline steps (numbered below) to implement this function ==

	// 1- Check if the Game is ended (Use the GetEndGame() function of pGrid), if yes, make the appropriate action

	// -- If not ended, do the following --:
	if(pManager->GetGrid()->GetEndGame()==0 )
	{
		Grid*pointertogrid=pManager->GetGrid();  
		//Get the "current" player from pGrid
		Player*currentplayer=pointertogrid->GetCurrentPlayer(); 
		Card* pCard=currentplayer->GetCell()->HasCard();  //Checks if player is currently in a cell containing a card
		if(pCard!=NULL)
		{
			if(pCard->GetCardNumber()==4)     //checks if player is in a cell containing card 4
			{
				int turnc=currentplayer->GetTurnCount();  
				
				if(turnc==3)
				{
					turnc=0;
					currentplayer->Setturncount(turnc);  
					return;
				}
				else
				{
					turnc++;
				currentplayer->Setturncount(turnc);  
				return;
				}
			}

		}
		// 2- Generate a random number from 1 to 6 --> This step is done for you
		srand((int)time(NULL)); // time is for different seed each run
		int diceNumber = 1 + rand() % 6; // from 1 to 6 --> should change seed

		// 4- Move the currentPlayer using function Move of class player
		currentplayer->Move(pointertogrid,diceNumber);  
		// 5- Advance the current player number of pGrid
		pointertogrid->AdvanceCurrentPlayer();  

		// NOTE: the above guidelines are the main ones but not a complete set (You may need to add more steps).
	}
	else
	{
		return; //Game has ended so dice will not be rolled

	}

}

RollDiceAction::~RollDiceAction()
{
}
