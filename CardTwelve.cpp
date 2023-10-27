#include "CardTwelve.h"

CardTwelve::CardTwelve(const CellPosition& position) : Card(position) // set the cell position of the card
{
	cardNumber = 12; // set the inherited cardNumber data member with the 12
	cardPrice = 0;  // initializing cardPrice & fees
	fees = 0;
}
CardTwelve::~CardTwelve() {}


void CardTwelve::Apply(Grid* pGrid, Player* pPlayer) {
	// 1- Call Apply() of the base class Card to print the message that you reached this card number
	Card* Card12Apply;
	Card12Apply->SetCardNumber(12);
	Card12Apply->Apply(pGrid, pPlayer);

	// 2 - call the output and input classes to print messages and take input
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	// 3 - find the poorest player

	int Curr_Pnum=pGrid-> GetcurrPlayerNumber();
	int min=10000;
	Player* Poor_Player;
	for (int i=0;i < MaxPlayerCount;i++) 
	{
		pGrid->SetcurrPlayerNumber(i);
		Player* Player_i = pGrid->GetCurrentPlayer();
		int Wallet_i=Player_i->GetWallet();                
			if(Wallet_i<min){
				min=Wallet_i;
				Poor_Player=Player_i;
		}		
	}
	pGrid->SetcurrPlayerNumber(Curr_Pnum);

	// 4 - get most expensive city owned by current player
	int max=0;
	city1=0;
	city2=0;
	city3=0;
	city4=0;
	city5=0;
	int cities[5] = { city1,city2,city3,city4,city5 };
	for (int i=0;i < 5;i++) {
	if(cities[i]>max && pGrid->GetCurrentPlayer() == owner)
	max=cities[i];
}
	//5- give the most expensive city to the poor
	Poor_Player=owner;
 CardTwelve::setOwner(Player* p) {
	owner = p;
}

int CardTwelve::getCardPrice() {
	return cardPrice;
}

}