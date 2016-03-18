#include "StdAfx.h"
#include "Stage1.h"
#include "StateMgr.h"

CStage1::CStage1(void)
{
}


CStage1::~CStage1(void)
{
	Release();
}

void CStage1::Initialize()
{

}

void CStage1::Progress()
{
	if (GetAsyncKeyState('2'))
	{
		CStateMgr::GetInst()->SetState(IDS_STAGE2);
		return;
	}
}

void CStage1::Render( HDC hdc )
{
	Rectangle(hdc , 100,100,200,200);
}

void CStage1::Release()
{

}
