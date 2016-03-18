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
	cout <<"������ �̸� : "<<m_tItem.strItName <<endl;
	cout <<"���� : "<<m_tItem.nOption <<"\t ���� : " <<m_tItem.nPrice<<endl;
}
