#include "StdAfx.h"
#include "Player.h"


CPlayer::CPlayer(void)
{
}


CPlayer::~CPlayer(void)
{
	Release();
}

void CPlayer::Initialize()
{
	m_tInfo = INFO(100,500,50,50);
	
	m_fSpeed = 5;


	m_bJump = false;
	m_fTime = 0;

	m_OffSetPosx = WINCX / 2;
}

void CPlayer::Progress()
{
	CheckKey();

	if (m_bJump == true)
	{
		Jump();
	}

	LineCol();
//	BoxCol();

	Scroll();
}

void CPlayer::Render( HDC hdc )
{
	Ellipse(hdc, 
		int(m_tInfo.fX - m_tInfo.fCX/2) + CObj::m_tScroll.x,
		int(m_tInfo.fY - m_tInfo.fCY/2),
		int(m_tInfo.fX + m_tInfo.fCX/2) + CObj::m_tScroll.x,
		int(m_tInfo.fY + m_tInfo.fCY/2)
		);

}

void CPlayer::Release()
{

}

void CPlayer::Jump()
{
	m_fTime += 0.1f;
	m_tInfo.fY += -sinf(90*PI/180) * 7 + (0.98f * m_fTime * m_fTime) /2;


}

void CPlayer::CheckKey()
{
	if(GetAsyncKeyState(VK_UP))
	{
		m_tInfo.fY -= m_fSpeed;
	}

	if(GetAsyncKeyState(VK_DOWN))
	{
		m_tInfo.fY += m_fSpeed;
	}

	if(GetAsyncKeyState(VK_LEFT))
	{
		m_tInfo.fX -= m_fSpeed;
	}

	if(GetAsyncKeyState(VK_RIGHT))
	{
		m_tInfo.fX += m_fSpeed;
	}
	if(GetAsyncKeyState(VK_SPACE))
	{
		if(m_bJump)
			return;

		m_bJump = true;
		
	}
}

void CPlayer::LineCol()
{
	LINE* pLine = NULL;

	for(list<LINE*>::iterator iter = m_pLineList->begin();
		iter != m_pLineList->end(); ++iter)
	{
		if(m_tInfo.fX >= (*iter)->tLPoint.x && 
			m_tInfo.fX <= (*iter)->tRPoint.x)
		{
			pLine = (*iter);
		}
	}

	if(pLine == NULL)
		return;

	float fWidth = pLine->tRPoint.x - pLine->tLPoint.x;
	float fHeight = pLine->tRPoint.y - pLine->tLPoint.y;

	float fy = (fHeight/fWidth) *(m_tInfo.fX - pLine->tLPoint.x) +pLine->tLPoint.y;

	if(!m_bJump)
		m_tInfo.fY = fy;

	if(m_tInfo.fY >=fy)
	{
		m_tInfo.fY = fy;
		m_bJump = false;
		m_fTime = 0.f;
	}


}

void CPlayer::BoxCol()
{
	RECT rcCol;
	
	if (IntersectRect(&rcCol,&GetRect(),&m_pBox->GetRect()))
	{
		SetRect(&rcCol,0,0,rcCol.right - rcCol.left, rcCol.bottom - rcCol.top);

		//옆에서 충돌 
		//Width < Height
		if (rcCol.right < rcCol.bottom)
		{
			//박스가 오른쪽 왼쪽에서 충돌
			if (m_tInfo.fX < m_pBox->GetInfo().fX)
			{
				m_tInfo.fX -= rcCol.right;
			}
			else //반대
			{
				m_tInfo.fX += rcCol.right;
			}
		}//밑에서 위에
		else
		{
			//밑에서 충돌
			if (m_tInfo.fY > m_pBox->GetInfo().fY)
			{
				m_tInfo.fY += rcCol.bottom;
			}
			else
			{
				m_tInfo.fY -= rcCol.bottom;
				
			}
		}
		
	}


}

void CPlayer::Scroll()
{
	if (m_OffSetPosx + 200 < m_tInfo.fX)
	{
		m_OffSetPosx += m_fSpeed;
		m_tScroll.x -= m_fSpeed;
	}

	if (m_OffSetPosx - 200 > m_tInfo.fX)
	{
		m_OffSetPosx -= m_fSpeed;
		m_tScroll.x += m_fSpeed;
	}


}
