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
	cout <<"아이템 이름 : "<<m_tItem.strItName <<endl;
	cout <<"옵션 : "<<m_tItem.nOption <<"\t 가격 : " <<m_tItem.nPrice<<endl;
}
