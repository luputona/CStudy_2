#include "StdAfx.h"
#include "Item.h"


CItem::CItem(void)
{
}

CItem::CItem( string _strItemName,int _nOption, int _nPrice ) :
m_tItem(_strItemName,_nOption,_nPrice)
{

}


CItem::~CItem(void)
{
}

void CItem::Render()
{
	cout <<"==========================================\n";
	cout <<"������ �̸� : "<<m_tItem.strItName <<endl;
	cout <<"�ɼ� : "<<m_tItem.nOption <<"\t ���� : " <<m_tItem.nPrice<<endl;
}
