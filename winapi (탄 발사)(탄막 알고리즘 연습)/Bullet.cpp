#include "StdAfx.h"
#include "Bullet.h"


CBullet::CBullet(void)
{
}

CBullet::~CBullet(void)
{
	Release();
}

void CBullet::Initalize()
{
	m_tInfo.nCX = 30;
	m_tInfo.nCY = 30;

	m_fAngle[0] = 0.33f;
	m_fAngle[1] = 0.f;

	m_fSpeed = 0.05f;

	m_fAngleRate[0] = 0.02f;
	m_fAngleRate[1] = -0.01f;

	m_fSpeedRate = 0.1f;
	m_nCount = 1;

	m_nTime = 0;
	m_nInterval = 10;
	m_nSpeed = 10;

	m_fBulletAngleRate = 0.4f;
	m_fBulletSpeedRate = 0.02f;

}

void CBullet::Progress()
{
	switch(m_eDir)
	{
	case DIR_UP:
		{			
			float fRad = m_fAngle[0] * PI * 2;
			////float fRad1 = m_fAngle[1] * PI * 2;

			m_tInfo.fX += m_fSpeed * cosf(fRad);
			m_tInfo.fY += m_fSpeed * sinf(fRad);

			////m_tInfo.fX += m_fSpeed * cosf(fRad1);
			////m_tInfo.fY += m_fSpeed * sinf(fRad1);


			//if ( m_nTime == 0)
			//{
			//	for (int j = 0; j<2; j++ )
			//	{
			//		for (int i = 0; i< m_nCount; i++)
			//		{	
			//			m_fAngle[j] = m_fAngle[j] + (float)i/m_nCount;
			//			m_fSpeed += m_fSpeedRate;				
			//		}
			//		m_fAngle[j] += m_fAngleRate[j];
			//		//m_fAngle[j] -= floor(m_fAngle[j]);
			//	}				
			//}
			//m_nTime = (m_nTime+1)%m_nInterval;
			//
			//m_fAngle += m_fAngleRate;
			//m_fAngle -= floor(m_fAngle);


			if (m_nTime == 0)
			{
				for (int i = 0; i<m_nCount; i++)
				{
					m_fAngle[0] = m_fAngle[0] + (float)i/m_nCount;
					m_fAngleRate[0] += m_fBulletAngleRate;
					m_fSpeed += m_fSpeed;
					m_fSpeedRate += m_fBulletSpeedRate;

				}
				m_fAngle[0] += m_fAngleRate[0];
				//m_fAngle[0] -= floor(m_fAngle[0]);
			}
			m_nTime = (m_nTime+1)%m_nInterval;
			

			break;
		}
		
	case DIR_DOWN:
		m_tInfo.fY +=m_nSpeed;
		break;
	case DIR_LEFT:
		m_tInfo.fX -= m_nSpeed;
		break;
	case DIR_RIGHT:
		m_tInfo.fX += m_nSpeed;
		break;
	case DIR_LU:
		m_tInfo.fX -= m_nSpeed;
		m_tInfo.fY -= m_nSpeed;
		break;
	case DIR_RU:
		m_tInfo.fX += m_nSpeed;
		m_tInfo.fY -= m_nSpeed;
		break;

	}

}

void CBullet::Render( HDC hdc )
{
	Ellipse(hdc, 
		m_tInfo.fX - m_tInfo.nCX/2,
		m_tInfo.fY - m_tInfo.nCY/2,
		m_tInfo.fX + m_tInfo.nCX/2,
		m_tInfo.fY + m_tInfo.nCY/2);
}

void CBullet::Release()
{

}
