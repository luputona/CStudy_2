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
	cout <<"������ �̸� : "<<m_tItem.strItName <<endl;
	cout <<"�ɼ� : "<<m_tItem.nOption <<"\t ���� : " <<m_tItem.nPrice<<endl;
	
}
