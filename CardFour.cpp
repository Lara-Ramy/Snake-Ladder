#include"CardFour.h"


CardFour::CardFour(const CellPosition & pos):Card(pos)
{
	cardNumber=4;
}

void CardFour:: ReadCardParameters(Grid * pGrid)
{
	//No Parameters

}
//void CardFour::Save(ofstream& OutFile, int num)
//{
//	if (num==3)
//{
		//OutFile << "4" <<endl;
//	}
	//OutFile <<position.GetCellNumFromPosition(position)<<endl;

//
//void CardFour::Load(ifstream& InFile, Grid* pGrid){
	//	Card*pC;
		//pC = new CardFour(position);
		//pGrid->AddObjectToCell(pC);
//}
void CardFour::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid,pPlayer); 

	ApplicationManager*pManager=new ApplicationManager();  
  
	pPlayer->DiceRoll(pManager);  

	delete pManager; 

}



CardFour:: ~CardFour(void)
{

}