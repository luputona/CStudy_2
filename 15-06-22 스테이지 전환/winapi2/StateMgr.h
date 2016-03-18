#pragma once
#include "Define.h"
class CStateObj;

//스테이지들을 관리
//얘는 메인이 사용 
class CStateMgr
{
private:
	CStateObj* m_pState;
public:
	CStateObj* GetState(void){ return m_pState; }
public:
	void SetState(STATEID _estate);
	void Release();

//싱글톤
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
//여러번 생성 안되게 생성자는 private로 
private:
	CStateMgr(void);
public:	
	~CStateMgr(void);
};

