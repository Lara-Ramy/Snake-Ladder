#include "Snake.h"
#include "iostream"


Snake::Snake(const CellPosition& startCellPos, const CellPosition& endCellPos) : GameObject(startCellPos)
{
	this->endCellPos = endCellPos;
}


void Snake::Draw(Output* pOut) const
{
	pOut->DrawSnake(position, endCellPos);
}


void Snake::Apply(Grid* pGrid, Player* pPlayer)
{
	pGrid->PrintErrorMessage("You have reached a snake. Click to continue...");

	pGrid->UpdatePlayerCell(pGrid->GetCurrentPlayer(),endCellPos);
}


CellPosition Snake::GetEndPosition() const
{
	return endCellPos;
}


bool Snake::isOverlapping(GameObject* newObj) const
{
		Snake* NewSnake = dynamic_cast<Snake*> (newObj);
		if (NewSnake)
		{
		    int OldHcell = this->endCellPos.HCell();

			int NewHcell = NewSnake->endCellPos.HCell();


			if (NewHcell == OldHcell)
			{
				int oldStart = this->endCellPos.VCell();

				int oldEnd = this->position.VCell();

				int NewStart = NewSnake->endCellPos.VCell();
				
				int NewEnd = NewSnake->position.VCell();
				
				
				for (int i = oldEnd; i <= oldStart; i++)
				{
					for (int j = NewEnd; j <= NewStart; j++)
					{
						if (i == j)
							return true;
					}
				}
			}
		}
		
		return false;
}


void Snake::Save(ofstream& OutFile, int l)
{
	if (l == 2){}
		//<<CellPosition::GetCellNumFromPosition(position)<<" "<<CellPosition::GetCellNumFromPosition(endCellPos)<<endl;
}

void Snake::Load(ifstream &Infile,Grid* pGrid)
{
	int Start, End;

	//Infile >> Start >> End;

	CellPosition startPos = CellPosition::GetCellPositionFromNum(Start);

	CellPosition endPos = CellPosition::GetCellPositionFromNum(End);

	Snake * snake = new Snake(startPos, endPos);


	if(pGrid->IsOverlapping(snake))
	{
		pGrid->PrintErrorMessage("Snake is overlapping..");

		return;
	}

	pGrid->AddObjectToCell(snake);
}



Snake::~Snake()
{
}