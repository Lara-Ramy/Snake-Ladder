#include"CardThree.h"




CardThree::CardThree(const CellPosition & pos ):Card(pos)
{
	cardNumber=3; 

}

void CardThree :: ReadCardParameters(Grid * pGrid)
{


}

void CardThree :: Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid,pPlayer);
	 
	ApplicationManager*pManager=new ApplicationManager();  
  
	pPlayer->DiceRoll(pManager);  

	delete pManager; 


}


CardThree :: ~CardThree(void)
{

}

//void CardEight::Save(ofstream& OutFile, int num)
//{
//	if (num == 3)
//	{
		//OutFile << "5" << endl;
//	}
	// << position.GetCellNumFromPosition(position) << endl;

//}
//void CardEight::Load(ifstream& InFile, Grid* pGrid) {
	//Card* pC;
	//pC = new CardEight(position);
	//pGrid->AddObjectToCell(pC);
//}
