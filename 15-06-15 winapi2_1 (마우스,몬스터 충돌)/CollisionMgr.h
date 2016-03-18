#pragma once
#include "Obj.h"


class CollisionMgr
{
public:
	static bool CircleCol(CObj* pTemp, CObj* pDest)
	{
		//������ + ������
		float fSum = (pTemp->GetInfo().fCX / 2) + (pDest->GetInfo().fCX/2);

		//�� ��ǥ�� �Ÿ�
		float fWidth = pTemp->GetInfo().fX - pDest->GetInfo().fX;
		float fHeight = pTemp->GetInfo().fY - pDest->GetInfo().fY;

		float fDistance = sqrt(fWidth * fWidth + fHeight * fHeight);

		//���������� ���� �� ũ�� �浹
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

