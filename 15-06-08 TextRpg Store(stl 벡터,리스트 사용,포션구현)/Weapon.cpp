#include "StdAfx.h"
#include "Weapon.h"


CWeapon::CWeapon(void)
{
}

CWeapon::CWeapon( string _strItName,int _nOption,int _nPrice,ITTYPE _eType,int _nItemType ) :
CItem(_strItName,_nOption,_nPrice,_eType)
{
	m_nItemType = _nItemType;
}

CWeapon::CWeapon( const CWeapon &rWeapon )
{
	m_tItem = rWeapon.m_tItem;
}


CWeapon::~CWeapon(void)
{
}

void CWeapon::Render()
{
	cout <<"==========================================\n";
	cout <<"아이템 이름 : "<<m_tItem.strItName <<endl;
	cout <<"공격력 : "<<m_tItem.nOption <<"\t 가격 : " <<m_tItem.nPrice<<endl;
	
}
