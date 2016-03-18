#include "StdAfx.h"
#include "Potion.h"


CPotion::CPotion(void)
{
}

CPotion::CPotion( string _strItName,int _nOption,int _nPrice,ITTYPE _eType,int _nItemType ) :
CItem(_strItName,_nOption,_nPrice,_eType)
{
	m_nItemType = _nItemType;

}

CPotion::CPotion( const CPotion& rPotion )
{
	m_tItem = rPotion.m_tItem;
	m_nItemType = rPotion.m_nItemType; //포션 갯수 체크 사용
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
