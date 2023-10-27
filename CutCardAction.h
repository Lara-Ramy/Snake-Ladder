#pragma once
#include "Action.h"
class CutCardAction : public Action
{
	// [Action Parameters]
	CellPosition cardPosition; // 1- cell position of the card
	int cardNumber;	           // 2 - card number
	// Note: These parameters should be read in ReadActionParameters()
public:
	CutCardAction(ApplicationManager* pApp); // A Constructor

	virtual void ReadActionParameters(); // Reads CopyCard action parameters (cardNumber, cardPosition)

	virtual void Execute(); // Creates a new Card Object of the specific Card Number
							// and Reads the Parameters of This Card Number (if any)
							// then Sets the clipboard to save this card
							// then it removes the card from the original cell

	virtual ~CutCardAction(); // A Virtual Destructor
};


