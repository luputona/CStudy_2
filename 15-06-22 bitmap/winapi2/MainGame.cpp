#include "StdAfx.h"
#include "MainGame.h"
#include "BitMap.h"

CMainGame::CMainGame(void)
{
}


CMainGame::~CMainGame(void)
{
	Release();
}

void CMainGame::Initialize()
{
	m_hdc = GetDC(g_hWnd);

	m_BitMap.push_back((new CBitMap)->LoadBmp(L"../Texture/BackBuffer.bmp"));
	m_BitMap.push_back((new CBitMap)->LoadBmp(L"../Texture/BackGround.bmp"));
	m_BitMap.push_back((new CBitMap)->LoadBmp(L"../Texture/Player/PlayerDOWN.bmp"));

	m_tinfo.fX = WINCX/2;
	m_tinfo.fY = WINCY/2;
	m_tinfo.fCX = 200;
	m_tinfo.fCY = 200;

}

void CMainGame::Progress()
{


}

void CMainGame::Render()
{
	//���
	BitBlt(m_BitMap[0]->GetMemDC(),0,0,WINCX,WINCY,m_BitMap[1]->GetMemDC(),0,0,SRCCOPY);

	

	�÷��̾�
	TransparentBlt(m_BitMap[0]->GetMemDC(),
		m_tinfo.fX - m_tinfo.fCX/2 ,  //�߾ӿ� ��ǥ�� ����� 
		m_tinfo.fY - m_tinfo.fCY/2 ,
		m_tinfo.fCX,m_tinfo.fCY,  //200,200 ����� 
		m_BitMap[2]->GetMemDC(),  //�÷��̾� 
		400,400, m_tinfo.fCX,m_tinfo.fCY,RGB(0,0,0) // �׸��� ��ǥ 
		);



	//������ �޸� ������ ����۸� �׸���, 
	//�����
	BitBlt(m_hdc,0,0,WINCX,WINCY,m_BitMap[0]->GetMemDC(),0,0,SRCCOPY); //
	
	


}

void CMainGame::Release()
{
	ReleaseDC(g_hWnd,m_hdc);
}
