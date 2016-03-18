#include "StdAfx.h"
#include "StateMgr.h"
#include "StateObj.h"
#include "Stage1.h"
#include "Stage2.h"

CStateMgr* CStateMgr::m_pInst = NULL; //스태틱 변수 초기화 

CStateMgr::CStateMgr(void) : 
m_pState(NULL)
{
}

CStateMgr::~CStateMgr(void)
{
	Release();
}

//스테이트 패턴
void CStateMgr::SetState( STATEID _estate )
{
	Safe_Delete(m_pState);

	switch(_estate)
	{
	case IDS_STAGE1:
		m_pState = new CStage1;
		break;
	case IDS_STAGE2:
		m_pState = new CStage2;
		break;
	}

	m_pState->Initialize();
}

void CStateMgr::Release()
{
	Safe_Delete(m_pState);
}
