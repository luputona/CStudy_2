#pragma once

const int EA = 3;


typedef struct tagInfo
{
	string strName;
	int nHp;
	int nAttack;
	int nMoney;

	tagInfo(){}
	tagInfo(string _strName,int _nHp, int _nAttack, int _nMoney) :
	strName(_strName),
	nHp(_nHp),
	nAttack(_nAttack),
	nMoney(_nMoney)
	{
	}
}INFO;

typedef struct tagItem
{
	string strItName;
	int nOption;
	int nPrice;

	tagItem(){}
	tagItem(string _strItName, int _nOption,int _nPrice) :
	strItName(_strItName),
	nOption(_nOption),
	nPrice(_nPrice)
	{
	}
}ITEM;