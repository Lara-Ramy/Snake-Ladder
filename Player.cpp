#include "Player.h"

#include "GameObject.h"

Player::Player(Cell * pCell, int playerNum) : stepCount(0), wallet(100), playerNum(playerNum)
{
	const CellPosition position=pCell->GetCellPosition();
	if(position.IsValidCell())
	{
		this->pCell = pCell;
	}

	this->turnCount = 0;
	this->justRolledDiceNum=0;
	this->Prison=0;
	this->Prisoned=0; 

	// Make all the needed initialization or validations
}

// ====== Setters and Getters ======

void Player::SetCell(Cell * cell)
{
	pCell = cell;
}

Cell* Player::GetCell() const
{
	return pCell;
}

void Player::SetWallet(int wallet)
{
	this->wallet = wallet;
	// Make any needed validations
}

int Player::GetWallet() const
{
	return wallet;
}

int Player::GetTurnCount() const
{
	return turnCount;
}
void Player::SetPrisoned(int n)
{
	Prisoned=n;
	Prison=0;
}
int Player::GetPrisoned() const
{
	return Prisoned;
}
void Player::Setturncount(int turnc)
{
	if(turnc>=0 && turnc<=3)
	{
		turnCount=turnc;
	}
	else
		return;
}
void Player:: SetjustRolledDiceNum(int dicenum)
{
	void SetjustRolledDiceNum(int dicenum);

}

void Player:: SetstepCount(int stepc) 
{
	if(stepc>=1 && stepc<=99)
		stepCount=stepc;

}
// ====== Drawing Functions ======

void Player::Draw(Output* pOut) const
{
	CellPosition playerpos=pCell->GetCellPosition();  //gets player cellposition (vcell and hcell)
	color playerColor = UI.PlayerColors[playerNum];
	pOut->DrawPlayer(playerpos,playerNum,playerColor);  //Draws player in cell



	///TODO: use the appropriate output function to draw the player with "playerColor"

}

void Player::ClearDrawing(Output* pOut) const
{
	CellPosition playerposition=pCell->GetCellPosition();  //gets player cellposition (vcell and hcell)
	color cellColor = pCell->HasCard() ? UI.CellColor_HasCard : UI.CellColor_NoCard;

	pOut->DrawPlayer(playerposition,playerNum,cellColor);  

	///TODO: use the appropriate output function to draw the player with "cellColor" (to clear it)

}

// ====== Game Functions ======

void Player::Move(Grid * pGrid, int diceNumber)
{

	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) to implement this function ==


	// 1- Increment the turnCount because calling Move() means that the player has rolled the dice once
	turnCount++; 
	if(Prisoned==1){
if(Prison<3){
Prison++;
return;
}
}
if(Prison=3){
SetPrisoned(0);
}
	// 2- Check the turnCount to know if the wallet recharge turn comes (recharge wallet instead of move)
	//    If yes, recharge wallet and reset the turnCount and return from the function (do NOT move)
	if(turnCount==3 )
	{
		SetWallet(this->wallet+10*diceNumber);
		turnCount=0; 
		return;
	}
	// 3- Set the justRolledDiceNum with the passed diceNumber
	SetjustRolledDiceNum(diceNumber); 
	// 4- Get the player current cell position, say "pos", and add to it the diceNumber (update the position)
	//    Using the appropriate function of CellPosition class to update "pos"
	CellPosition pos=pCell->GetGameObject()->GetPosition();  //Class player has a pointer to class cell as a data member
	//calls getter for gameobject in class cell which returns a pointer to gameobject
	//then calls function getposition in class gameobject which returns a cellposition object
	pos.AddCellNum(diceNumber); //updates the data members (vCell and hCell) of the calling object 
	// 5- Use pGrid->UpdatePlayerCell() func to Update player's cell POINTER (pCell) with the cell in the passed position, "pos" (the updated one)
	//    the importance of this function is that it Updates the pCell pointer of the player and Draws it in the new position
	pGrid->UpdatePlayerCell(this,pos);  
	// 6- Apply() the game object of the reached cell (if any)
	if(pCell->GetGameObject()!=NULL )  //checks if current cell contains a gameobject or not
	{
		GameObject*gameobject=pCell->GetGameObject() ;    //returns pointer to game object
		gameobject->Apply(pGrid, this);                   //Applies effect of gameobject on player
		//For example if gameobject is ladder it calls it calls the apply version of ladder class   
		//It is a purevirtual function in class Gameobject that is overridden in the derived classes(Ladder,etc..)
	}
	// 7- Check if the player reached the end cell of the whole game, and if yes, Set end game with true: pGrid->SetEndGame(true)
	if(pCell->GetCellPosition().GetCellNum()==99)
	{

		pGrid->SetEndGame(true);  

	}


}


void Player:: DiceRoll(ApplicationManager* pManager)  //Calls function execute in RollDiceAction
{


	pManager->ExecuteAction(ROLL_DICE);    

}

void Player::AppendPlayerInfo(string & playersInfo) const
{
	playersInfo += "P" + to_string(playerNum) + "(" ;
	playersInfo += to_string(wallet) + ", ";
	playersInfo += to_string(turnCount) + ")";
}

int Player::GetJustRolledDiceNum() {
	return justRolledDiceNum;
}