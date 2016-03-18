#include "StdAfx.h"
#include "StageBack.h"


CStageBack::CStageBack(void)
{
}


CStageBack::~CStageBack(void)
{
}

void CStageBack::Initialize()
{

}

int CStageBack::Progress()
{
	return 0;
}

void CStageBack::Render( HDC hdc )
{
	BitBlt(hdc,0,0,WINCX,WINCY ,
		(*m_pMapBmp)["BackGround"]->GetMemDC(),0,0,SRCCOPY);
}

void CStageBack::Release()
{

}
