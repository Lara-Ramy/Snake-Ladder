#include"NewGameAction.h"

#include"Player.h"
#include"Grid.h"
NewGameAction::NewGameAction(ApplicationManager *pApp) :Action(pApp) 
{

}

void NewGameAction::ReadActionParameters()
{


}

void NewGameAction::Execute()   //Restarts players' positions, wallets, and turn returns to player 0
{
	Grid*pGrid=pManager->GetGrid();  //Getting a pointer to grid

	Player*Pointertocurrentplayer=pGrid->GetCurrentPlayer();   //Getting a pointer to current player

	int c=0;

	while(c<4)
	{

		int wallet=100;  
		int defcellnum=1;
		Pointertocurrentplayer->SetWallet(wallet);                 //Setting player wallet to default value(100) 
		CellPosition restart(defcellnum);                          
		pGrid->UpdatePlayerCell(Pointertocurrentplayer,restart) ;  //// Update the player's pCell with the CellList's Cell pointer to cell number 1 ,
	                                                                          // Clears the player's circle from the previous cell
	    																	  // and  Draws it in cell number 1
		Pointertocurrentplayer->SetstepCount(defcellnum);  
		
		
		
		pGrid->AdvanceCurrentPlayer();      // Increments the currPlayerNum and if reaches MaxPlayerCount(4) reset to 0

		c++;

	}
	int playertoplay=0;
	pGrid->SetcurrPlayerNumber(playertoplay);   //Returning the turn to player 0 after reseting the players' positions and wallets

}
NewGameAction :: ~NewGameAction ()
{

}