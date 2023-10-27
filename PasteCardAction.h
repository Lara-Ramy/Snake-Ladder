#pragma once
#include "Action.h"
class PasteCardAction : public Action
{
	// [Action Parameters]
	CellPosition cardPosition; // 1- cell position of the card
	int cardNumber;	           // 2 - card number
	// Note: These parameters should be read in ReadActionParameters()
public:
	PasteCardAction(ApplicationManager* pApp); // A Constructor

	virtual void ReadActionParameters(); // Reads PasteCardAction action parameters (cardNumber, cardPosition)

	virtual void Execute(); // gets the card from clipboard
							// and Reads the Parameters of This Card Number (if any)
							// then adds the card to the required cell

	virtual ~PasteCardAction(); // A Virtual Destructor
};

