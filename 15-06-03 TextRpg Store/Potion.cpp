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
	cout <<"������ �̸� : "<<m_tItem.strItName <<endl;
	cout <<"ȸ�� : "<<m_tItem.nOption <<"\t ���� : " <<m_tItem.nPrice<<endl;
}
