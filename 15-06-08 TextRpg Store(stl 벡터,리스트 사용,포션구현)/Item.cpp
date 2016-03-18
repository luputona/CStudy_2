#include "StdAfx.h"
#include "Item.h"


CItem::CItem(void)
{
}

CItem::CItem( string _strItemName,int _nOption, int _nPrice, ITTYPE _eType ) : 
m_tItem(_strItemName,_nOption,_nPrice,_eType),
m_nItemType(0)
{

}


CItem::~CItem(void)
{
}
