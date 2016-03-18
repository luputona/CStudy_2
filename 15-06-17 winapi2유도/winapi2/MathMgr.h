#pragma once
#include "Obj.h"

class CMathMgr
{
public:
	static float GetDistance(CObj* pTemp,CObj* pDest)
	{
		float fWidth = pTemp->GetInfo().fX - pDest->GetInfo().fX;
		float fHeight = pTemp->GetInfo().fY - pDest->GetInfo().fY;
		float fDistance = sqrt(fWidth*fWidth + fHeight * fHeight);

		return fDistance;
	}

	static float GetAngle(CObj* pTemp , CObj* pDest)
	{
		float fWidth = pTemp->GetInfo().fX - pDest->GetInfo().fX;
		float fHeight = pTemp->GetInfo().fY - pDest->GetInfo().fY;
		float fDistance = sqrt(fWidth*fWidth + fHeight * fHeight);

		float fAngle = acosf(fWidth/fDistance) *180 /PI;

		if(pTemp->GetInfo().fY> pDest->GetInfo().fY)
		{
			fAngle = 360 - fAngle;
		}

		return fAngle;

	}


public:
	CMathMgr(void);
	~CMathMgr(void);
};

