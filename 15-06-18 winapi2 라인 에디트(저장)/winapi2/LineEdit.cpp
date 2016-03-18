#include "StdAfx.h"
#include "LineEdit.h"
#include "Mouse.h"

CLineEdit::CLineEdit(void)
{
}


CLineEdit::~CLineEdit(void)
{
}

void CLineEdit::WriteData()
{
	if (MessageBox(g_hWnd,L"저장!",L"SystemMessage",MB_OKCANCEL) == IDCANCEL)
	{
		return;
	}

	HANDLE hFile;
	DWORD dwByte;

	hFile = CreateFile(L"../Data/Line.dat",GENERIC_WRITE,NULL, NULL, CREATE_ALWAYS,FILE_ATTRIBUTE_NORMAL,NULL);

	for (list<LINE*>::iterator iter = m_LineList.begin(); iter != m_LineList.end(); ++iter)
	{
		WriteFile(hFile,(*iter),sizeof(LINE),&dwByte,NULL);
	}

	CloseHandle(hFile);
}

void CLineEdit::Initialize()
{
	m_bStart = false;

	m_tScrollPos.x = 0.f;
	m_tScrollPos.y = 0.f;
	m_fSpeed = 5.0f;

}

void CLineEdit::Progress()
{
	POINTFLOAT MousePos;

	MousePos.x = CMouse::GetPos().x - m_tScrollPos.x; //반대로 줘서 원상태로 감 
	MousePos.y = CMouse::GetPos().y - m_tScrollPos.y;


	if (GetAsyncKeyState(VK_LEFT))
	{
		m_tScrollPos.x += m_fSpeed;
	}
	if (GetAsyncKeyState(VK_RIGHT))
	{
		m_tScrollPos.x -= m_fSpeed;
	}
	if (GetAsyncKeyState('S'))
	{
		m_tStartPoint = MousePos;
		m_bStart = true;
	}

	if (GetAsyncKeyState(VK_LBUTTON)) // 한번씩 클릭되게 조정 0x0001
	{
		if (m_bStart)
		{
			m_LineList.push_back(new LINE(m_tStartPoint,MousePos));
			m_bStart = false;
		}
		m_LineList.push_back(new LINE(m_LineList.back()->tRPoint,MousePos));
	}
	if (GetAsyncKeyState(VK_RETURN))
	{
		WriteData();

	}

}

void CLineEdit::Render( HDC hdc )
{
	MoveToEx(hdc,int(m_tStartPoint.x + m_tScrollPos.x),int(m_tStartPoint.y),NULL);

	for (list<LINE*>::iterator iter = m_LineList.begin(); iter != m_LineList.end();++iter)
	{
		LineTo(hdc,int((*iter)->tRPoint.x + m_tScrollPos.x),int((*iter)->tRPoint.y));
	}
}

void CLineEdit::Release()
{
	for (list<LINE*>::iterator iter = m_LineList.begin(); iter != m_LineList.end();++iter)
	{
		Safe_Delete(*iter);
	}
	m_LineList.clear();
}
