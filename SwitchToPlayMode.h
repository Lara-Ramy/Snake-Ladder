#pragma once
#include "Action.h"
#include"Grid.h"
#include"Player.h"

class SwitchToPlayMode : public Action
{

public:
	
	SwitchToPlayMode(ApplicationManager* pApp);
	
	void ReadActionParameters();
	
	void Execute();
	
	~SwitchToPlayMode(void);
};
