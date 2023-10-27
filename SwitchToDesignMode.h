#pragma once
#include "Action.h"
#include"Grid.h"
#include"Player.h"

class SwitchToDesignMode : public Action
{

public:
	
	SwitchToDesignMode(ApplicationManager* pApp);
	
	void ReadActionParameters();
	
	void Execute();
	
	~SwitchToDesignMode(void);
};