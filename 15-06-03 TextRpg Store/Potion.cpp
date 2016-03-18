#include "StdAfx.h"
#include "Potion.h"


CPotion::CPotion(void)
{
}

CPotion::CPotion( string _strItName,int _nOption,int _nPrice,ITTYPE _eType ) :
CItem(_strItName,_nOption,_nPrice,_eType)
{

}


CPotion::~CPotion(void)
{
}

void CPotion::Render()
{
	cout <<"==========================================\n";
	cout <<"아이템 이름 : "<<m_tItem.strItName <<endl;
	cout <<"회복 : "<<m_tItem.nOption <<"\t 가격 : " <<m_tItem.nPrice<<endl;
}
