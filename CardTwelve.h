#pragma once
#include "Card.h"
class CardTwelve : public Card
{
	int cardPrice;
	int fees;
	int number;
	bool isBought;
	Player* owner;

public:
	CardTwelve(const CellPosition& position);			//Nondefault constructor that takes cardPosition
	virtual ~CardTwelve();							//destructor

	virtual void ReadCardParameters(Grid* pGrid); 

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of CardTwelve on the passed Player

	void setOwner(Player* p);						  // changes the owner to be used in card 12

	int getCardPrice(void);							  // gets the card price to be used in card 12
};

