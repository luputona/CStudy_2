#pragma once
#include "Define.h"
class CStateObj;

//������������ ����
//��� ������ ��� 
class CStateMgr
{
private:
	CStateObj* m_pState;
public:
	CStateObj* GetState(void){ return m_pState; }
public:
	void SetState(STATEID _estate);
	void Release();

//�̱���
private:
	static CStateMgr* m_pInst; 

public:
	static CStateMgr* GetInst()
	{
		if (m_pInst == NULL)
		{
			m_pInst = new CStateMgr;
		}
		return m_pInst;
	}
	void DestroyInst()
	{
		delete m_pInst;
		m_pInst = NULL;
	}
//������ ���� �ȵǰ� �����ڴ� private�� 
private:
	CStateMgr(void);
public:	
	~CStateMgr(void);
};

