#include "StdAfx.h"
#include "Armor.h"


CArmor::CArmor(void)
{
}

CArmor::CArmor( string _strAmName,int _nOption,int _nPrice,ITTYPE _eType ,int _nItemType) :
CItem(_strAmName,_nOption,_nPrice,_eType)
{
	m_nItemType = _nItemType;
}

CArmor::CArmor( const CArmor& rArmor )
{
	m_tItem = rArmor.m_tItem;
}


CArmor::~CArmor(void)
{
}

void CArmor::Render()
{
	cout <<"==========================================\n";
	cout <<"아이템 이름 : "<<m_tItem.strItName <<endl;
	cout <<"방어력 : "<<m_tItem.nOption <<"\t 가격 : " <<m_tItem.nPrice<<endl;
}
