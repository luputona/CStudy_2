#include "StdAfx.h"
#include "Weapon.h"


CWeapon::CWeapon(void)
{
}

CWeapon::CWeapon( string _strItName,int _nOption,int _nPrice,ITTYPE _eType ) :
CItem(_strItName,_nOption,_nPrice,_eType)
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
