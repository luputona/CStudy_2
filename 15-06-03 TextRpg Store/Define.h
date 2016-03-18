#pragma once

#define SAFE_DELETE(p) if(p) {delete p; p = NULL;}

const int EA = 3;
enum ITTYPE
{
	ITWEAPON,
	ITARMOR,	
	ITPOTION,
	ITEND
};

typedef struct tagInfo
{
	string strName;
	int nHp;
	int nAttack;
	int nDef;
	int nMoney;

	tagInfo(){}
	tagInfo(string _strName,int _nHp, int _nAttack, int _nMoney,int _nDef) :
	strName(_strName),
	nHp(_nHp),
	nAttack(_nAttack),
	nMoney(_nMoney),
	nDef(_nDef)
	{
	}
}INFO;

typedef struct tagItem
{
	string strItName;
	int nOption;
	int nPrice;
	ITTYPE eType;

	tagItem(){}
	tagItem(string _strItName, int _nOption,int _nPrice,ITTYPE _eType) :
	strItName(_strItName),
	nOption(_nOption),
	nPrice(_nPrice),
	eType(_eType)
	{
	}
}ITEM;

