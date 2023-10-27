#include "Ladder.h"
#include <fstream>

Ladder::Ladder(const CellPosition & startCellPos, const CellPosition & endCellPos) : GameObject(startCellPos)
{
	this->endCellPos = endCellPos;

	///TODO: Do the needed validation
}

void Ladder::Draw(Output* pOut) const
{
	pOut->DrawLadder(position, endCellPos);
}

void Ladder::Apply(Grid* pGrid, Player* pPlayer) 
{
	

	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) to implement this function ==
	
	// 1- Print a message "You have reached a ladder. Click to continue ..." and wait mouse click
	pGrid->PrintErrorMessage("You have reached a ladder.Click to continue...");

	// 2- Apply the ladder's effect by moving the player to the endCellPos
	pGrid->UpdatePlayerCell(pGrid->GetCurrentPlayer(),endCellPos);
	//    Review the "pGrid" functions and decide which function can be used for that
	
}

bool Ladder::isOverlapping(GameObject* newObj) const
{
	Ladder* NewLadder = dynamic_cast<Ladder*> (newObj);

	if (NewLadder)
	{
		int OldHCell = this->endCellPos.HCell();

		int NewHCell = NewLadder->endCellPos.HCell();

		if (NewHCell == OldHCell)
		{
			int OldStart = this->endCellPos.VCell();

			int OldEnd = this->position.VCell();

			int NewStart = NewLadder->endCellPos.VCell();

			int NewEnd = NewLadder->position.VCell();


			for (int i = OldStart; i <= OldEnd; i++)
			{
				for (int j = NewStart; j <= NewEnd; j++)
				{
					if (i == j)
						return true;
				}
			}
		}
	}
	return false;
	
}  


void Ladder :: Save(ofstream& OutFile , int l)
{
	if (l == 1)
		OutFile << CellPosition::GetCellNumFromPosition(position) << " " << CellPosition::GetCellNumFromPosition(endCellPos) << endl;
}

void Ladder::Load(ifstream &Infile,Grid* pGrid)
{
	int Start, End;

	Infile >> Start >> End;

	CellPosition startPos = CellPosition::GetCellPositionFromNum(Start);

	CellPosition endPos = CellPosition::GetCellPositionFromNum(End);

	Ladder * ladder = new Ladder(startPos, endPos);

	if(pGrid->IsOverlapping(ladder))
	{
		pGrid->PrintErrorMessage("Ladder is overlapping..");

		return;
	}

	pGrid->AddObjectToCell(ladder);
}



CellPosition Ladder::GetEndPosition() const
{
	return endCellPos;
}

Ladder::~Ladder()
{
}
