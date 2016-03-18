#include "StdAfx.h"
#include "ColMgr.h"
#include "Obj.h"

CColMgr::CColMgr(void)
{
}


CColMgr::~CColMgr(void)
{
}

void CColMgr::ColRect( list<CObj*>* pTemp, list<CObj*>* pDest )
{
	RECT rc;

	for (list<CObj*>::iterator iter1 = pTemp->begin(); iter1 != pTemp->end(); ++iter1)
	{
		for (list<CObj*>::iterator iter2 = pDest->begin(); iter2 != pDest->end(); )
		{
			if (IntersectRect(&rc,&(*iter1)->GetRect(),&(*iter2)->GetRect()))
			{
				Safe_Delete(*iter1);
				Safe_Delete(*iter2);

				iter1 = pTemp->erase(iter1);
				iter2 = pDest->erase(iter2);
			}
			else
			{
				++iter2;
			}
			if (iter1 == pTemp->end())
			{
				break;
			}
		}
		if (iter1 == pTemp->end())
		{
			break;
		}
	}


}
