#include "StdAfx.h"
#include "Player.h"
#include "Item.h"


CPlayer::CPlayer(void) :
m_nEquipAtt(0),
m_nEquipDef(0),
m_pItem2(NULL)
{
	memset(m_pItem,0,sizeof(m_pItem));
}

CPlayer::CPlayer( string _strName,int _nHp,int _nAttack,int _nMoney,int _nDef ):
CObj(_strName,_nHp,_nAttack,_nMoney,_nDef)
{

}


CPlayer::~CPlayer(void)
{
}

void CPlayer::SelectJob()
{
	cout << "������ �Է� �ϼ��� (1.���� 2.���� 3.������) : ";
	int nInput = 0;
	cin >> nInput;


	switch(nInput)
	{
	case 1:
		m_tInfo.strName = " ����";
		m_tInfo.nHp = 150;
		m_tInfo.nAttack = 10;
		m_tInfo.nDef = 4;
		m_tInfo.nMoney = 10000;
		m_nEquipAtt = m_tInfo.nAttack;
		m_nEquipDef = m_tInfo.nDef;
		m_nEquipHp = m_tInfo.nHp;
		break;
	case 2:
		m_tInfo.strName = " ����";
		m_tInfo.nHp = 130;
		m_tInfo.nAttack = 8;
		m_tInfo.nDef = 2;
		m_tInfo.nMoney = 15000;
		m_nEquipAtt = m_tInfo.nAttack;
		m_nEquipDef = m_tInfo.nDef;
		m_nEquipHp = m_tInfo.nHp;
		break;
	case 3:
		m_tInfo.strName = " ������";
		m_tInfo.nHp = 100;
		m_tInfo.nAttack = 15;
		m_tInfo.nDef = 1;
		m_tInfo.nMoney = 10000;
		m_nEquipAtt = m_tInfo.nAttack;
		m_nEquipDef = m_tInfo.nDef;
		m_nEquipHp = m_tInfo.nHp;
		break;
	}
}

void CPlayer::Render()
{
	
	cout <<"==========================================\n";
	cout <<"���� �̸� : "<<m_tInfo.strName <<"\t ������ : "<<m_tInfo.nMoney<<endl;
	cout <<"ü�� : "<<m_tInfo.nHp<<"\t ���ݷ� : "<<m_tInfo.nAttack<< "\t ���� : "<<m_tInfo.nDef<<endl;
	
	
}

void CPlayer::SetEquipItem( CItem *pItem )
{
	m_pItem[pItem->GetItem().eType] = pItem;

	switch(pItem->GetItem().eType)
	{
	case ITWEAPON:
		m_tInfo.nAttack = m_nEquipAtt + pItem->GetItem().nOption;		
		break;
	case ITARMOR:
		m_tInfo.nDef = m_nEquipDef + pItem->GetItem().nOption;
		break;
	case ITPOTION:
		m_tInfo.nHp = m_nEquipHp + pItem->GetItem().nOption;		
		break;

	}

}
