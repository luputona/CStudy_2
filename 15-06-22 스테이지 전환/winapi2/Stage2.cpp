#include "StdAfx.h"
#include "Stage2.h"
#include "StateMgr.h"

CStage2::CStage2(void)
{
}


CStage2::~CStage2(void)
{
	Release();
}

void CStage2::Initialize()
{

}

void CStage2::Progress()
{
	if (GetAsyncKeyState('1'))
	{
		CStateMgr::GetInst()->SetState(IDS_STAGE1);
		return;
	}
}

void CStage2::Render( HDC hdc )
{
	Ellipse(hdc,300,300,400,400);
}

void CStage2::Release()
{

}
