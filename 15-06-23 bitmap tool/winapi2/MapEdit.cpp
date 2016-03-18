#include "StdAfx.h"
#include "MapEdit.h"
#include "BitMap.h"
#include "Mouse.h"

CMapEdit::CMapEdit(void)
{
}


CMapEdit::~CMapEdit(void)
{
	Release();
}

void CMapEdit::Initialize()
{
	m_vecBmp.push_back((new CBitMap)->LoadBmp(L"../Texture/BackBuffer.bmp"));
	m_vecBmp.push_back((new CBitMap)->LoadBmp(L"../Texture/Tile.bmp"));

	InitTile();
	
	m_fSpeed = 5.f;
	m_fScrollX = 0.f;
	m_fScrollY = 0.f;
	m_bIDCheck = false;
}

void CMapEdit::Progress()
{
	CheckKey();
	Scroll();
}

void CMapEdit::Render(HDC hdc)
{
	for (int i = 0; i<TILEY; ++i)
	{
		for (int j = 0; j<TILEX; ++j)
		{
			int nIndex = i * TILEX + j;

			BitBlt(m_vecBmp[0]->GetMemDC(),
				int((m_vecTile[nIndex]->fX - TILECX/2 + m_fScrollX )), //Å¸ÀÏ Áß¾Ó 
				int((m_vecTile[nIndex]->fY - TILECY/2 + m_fScrollY )),
				TILECX,TILECY,
				m_vecBmp[1]->GetMemDC(),
				m_vecTile[nIndex]->nDrawID * TILECX,
				0,SRCCOPY);
		}
	}

	BitBlt(hdc,0,0,WINCX,WINCY,m_vecBmp[0]->GetMemDC(),0,0,SRCCOPY);


}

void CMapEdit::Release()
{
	for (size_t i = 0; i<m_vecTile.size(); ++i)
	{
		Safe_Delete(m_vecTile[i]);
	}
	m_vecTile.clear();
}

void CMapEdit::InitTile( void )
{
	for(int i =0; i<TILEY; ++i)
	{
		for (int j = 0; j<TILEX; ++j)
		{
			float fx = (j*TILECX) + TILECX/2;
			float fy = (i*TILECY) + TILECY/2;

			m_vecTile.push_back(CreateTile(fx,fy));
		}
	}

	
}

TILE* CMapEdit::CreateTile( float _fx, float _fy )
{
	TILE* pTile = new TILE;

	pTile->fX = _fx;
	pTile->fY = _fy;
	pTile->fCX = TILECX;
	pTile->fCY = TILECY;
	pTile->nDrawID = 0;
	pTile->nOption = 0;


	return pTile;
}

void CMapEdit::Picking()
{
	int nX = (CMouse::GetPos().x - m_fScrollX) / TILECX;
	int nY = (CMouse::GetPos().y - m_fScrollY) / TILECY;

	int nIndex = nY * TILEX + nX;

	if (m_bIDCheck = true)
	{
		m_vecTile[nIndex]->nDrawID = 1;
		m_vecTile[nIndex]->nOption = 1;

	}	

	if (m_bIDCheck == false)
	{
		m_vecTile[nIndex]->nDrawID = 0;
		m_vecTile[nIndex]->nOption = 0;
	}
	

}

void CMapEdit::CheckKey()
{
	if (GetAsyncKeyState(VK_LEFT))
	{
		m_fScrollX += m_fSpeed;
	}
	if (GetAsyncKeyState(VK_RIGHT))
	{
		m_fScrollX -= m_fSpeed;
	}
	if (GetAsyncKeyState(VK_UP))
	{
		m_fScrollY += m_fSpeed;
	}
	if (GetAsyncKeyState(VK_DOWN))
	{
		m_fScrollY -= m_fSpeed;
	}
	if (GetAsyncKeyState(VK_LBUTTON))
	{
		m_bIDCheck = true;
		Picking();
		if (m_bIDCheck == true)
		{
			if(GetAsyncKeyState(VK_LBUTTON))
			{
				m_bIDCheck = false;
				Picking();
			}
		}
	}



}

void CMapEdit::Scroll()
{
	if (m_fScrollX > 0)
	{
		m_fScrollX = 0;
	}
	
	if (m_fScrollY > 0)
	{
		m_fScrollY = 0;
	}

	if (m_fScrollX < WINCX - (TILECX * TILEX)) //°¹¼ö °öÇÏ±â »çÀÌÁî = ÀüÃ¼Å©±â
	{
		m_fScrollX = WINCX - (TILECX * TILEX);
	}

	if (m_fScrollY < WINCY - (TILECY * TILEY))
	{
		m_fScrollY = WINCY - (TILECY * TILEY);
	}

}
