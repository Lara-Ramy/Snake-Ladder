#include"Action.h"


class InputDiceValueAction: public Action
{

	int inputdicevalue;

public:

	InputDiceValueAction(ApplicationManager* pAppManager ); 

	virtual void ReadActionParameters();

	virtual void Execute();

	virtual ~InputDiceValueAction();



};