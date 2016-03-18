#include "StdAfx.h"
#include "Ball.h"


CBall::CBall(void)
{
}


CBall::~CBall(void)
{
}

void CBall::Initialize()
{
	m_tBall.nReady = 1;
	m_tBall.nDirect = 0;
	m_tBall.nX = 30;
	m_tBall.nY = 10;
}

void CBall::Progress()
{
	KeyInput();

	if (m_tBall.nReady == 0)
	{
		switch(m_tBall.nDirect)
		{
		case 0:
			if (Collision(m_tBall.nX,m_tBall.nY-1) == 0)
			{
				m_tBall.nY--;
			}
			break;
		case 1:
			if (Collision(m_tBall.nX+1,m_tBall.nY-1) == 0)
			{
				m_tBall.nX++;
				m_tBall.nY--;
			}
			break;
		case 2:
			if (Collision(m_tBall.nX+1,m_tBall.nY+1) == 0)
			{
				m_tBall.nX++;
				m_tBall.nY++;
			}
			break;
		case 3:
			if (Collision(m_tBall.nX,m_tBall.nY+1) == 0)
			{				
				m_tBall.nY++;
			}
			break;
		case 4:
			if (Collision(m_tBall.nX-1,m_tBall.nY+1) == 0)
			{
				m_tBall.nX--;
				m_tBall.nY++;
			}
			break;
		case 5:
			if (Collision(m_tBall.nX-1,m_tBall.nY-1) == 0)
			{
				m_tBall.nX--;;
				m_tBall.nY--;
			}
			break;
		}
	}


}

void CBall::Render()
{
	//ScreenLine();
	system("cls");
	gotoxy(m_tBall.nX,m_tBall.nY);
	cout<<"≒";
}

void CBall::Release()
{

}

void CBall::ScreenLine()
{
	gotoxy(0,0);
	cout <<"旨收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旬"<<endl;
	cout <<"早                                                                          早"<<endl;
	cout <<"早                                                                          早"<<endl;
	cout <<"早                                                                          早"<<endl;
	cout <<"早                                                                          早"<<endl;
	cout <<"早                                                                          早"<<endl;
	cout <<"早                                                                          早"<<endl;
	cout <<"早                                                                          早"<<endl;
	cout <<"早                                                                          早"<<endl;
	cout <<"早                                                                          早"<<endl;
	cout <<"早                                                                          早"<<endl;
	cout <<"早                                                                          早"<<endl;
	cout <<"早                                                                          早"<<endl;
	cout <<"早                                                                          早"<<endl;
	cout <<"早                                                                          早"<<endl;
	cout <<"早                                                                          早"<<endl;
	cout <<"早                                                                          早"<<endl;
	cout <<"早                                                                          早"<<endl;
	cout <<"早                                                                          早"<<endl;
	cout <<"早                                                                          早"<<endl;
	cout <<"早                                                                          早"<<endl;
	cout <<"早                                                                          早"<<endl;
	cout <<"曲收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旭"<<endl;


}

int CBall::Collision( int x, int y )
{
	if (y == 0)
	{
		m_tBall.nDirect = g_WallCollision[0][m_tBall.nDirect];
		return 1;
	}
	if (x==1)
	{
		m_tBall.nDirect = g_WallCollision[1][m_tBall.nDirect];
		return 1;
	}

	if (x == 77)
	{
		m_tBall.nDirect = g_WallCollision[2][m_tBall.nDirect];
		return 1;
	}
	if (y == 23)
	{
		m_tBall.nDirect = g_WallCollision[3][m_tBall.nDirect];
		return 1;
	}

	return 0;
}

void CBall::KeyInput()
{
	int nKey;

	if(_kbhit())
	{
		nKey = _getch();

		switch(nKey)
		{
		case '0':
			m_tBall.nDirect = 0;
			m_tBall.nX = 30;
			m_tBall.nY = 10;
			break;
		case '1':
			m_tBall.nDirect = 1;
			m_tBall.nX = 30;
			m_tBall.nY = 10;
			break;
		case '2':
			m_tBall.nDirect = 2;
			m_tBall.nX = 30;
			m_tBall.nY = 10;
			break;
		case '3':
			m_tBall.nDirect = 3;
			m_tBall.nX = 30;
			m_tBall.nY = 10;
			break;
		case '4':
			m_tBall.nDirect = 4;
			m_tBall.nX = 30;
			m_tBall.nY = 10;
			break;
		case '5':
			m_tBall.nDirect = 5;
			m_tBall.nX = 30;
			m_tBall.nY = 10;
			break;
		case 'f':
			m_tBall.nReady = 0;
			break;
		case  'r':
			m_tBall.nReady = 1;
			m_tBall.nX = 30;
			m_tBall.nY = 10;
			break;
		}
	}
}
