#pragma once
#include "Obj.h"


class CollisionMgr
{
public:
	static bool CircleCol(CObj* pTemp, CObj* pDest)
	{
		//반지름 + 반지름
		float fSum = (pTemp->GetInfo().fCX / 2) + (pDest->GetInfo().fCX/2);

		//각 좌표의 거리
		float fWidth = pTemp->GetInfo().fX - pDest->GetInfo().fX;
		float fHeight = pTemp->GetInfo().fY - pDest->GetInfo().fY;

		float fDistance = sqrt(fWidth * fWidth + fHeight * fHeight);

		//반지름끼리 합이 더 크면 충돌
		if (fSum > fDistance)
		{
			return true;
		}
		
		return false;
	}
public:
	CollisionMgr(void);
	~CollisionMgr(void);
};

