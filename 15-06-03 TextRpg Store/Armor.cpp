#include "StdAfx.h"
#include "Armor.h"


CArmor::CArmor(void)
{
}

CArmor::CArmor( string _strAmName,int _nOption,int _nPrice,ITTYPE _eType ) :
CItem(_strAmName,_nOption,_nPrice,_eType)
{

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
