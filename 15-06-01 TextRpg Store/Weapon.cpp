#include "StdAfx.h"
#include "Weapon.h"


CWeapon::CWeapon(void)
{
}

CWeapon::CWeapon( string _strItName,int _nOption,int _nPrice ) :
m_tItem(_strItName,_nOption,_nPrice)
{

}


CWeapon::~CWeapon(void)
{
}

void CWeapon::Render()
{
	cout <<"==========================================\n";
	cout <<"아이템 이름 : "<<m_tItem.strItName <<endl;
	cout <<"옵션 : "<<m_tItem.nOption <<"\t 가격 : " <<m_tItem.nPrice<<endl;
	
}
