#pragma once
#include "Define.h"


class CObj;
class CColMgr
{
public:
	static void ColRect(list<CObj*>* pTemp, list<CObj*>* pDest);
public:
	CColMgr(void);
	~CColMgr(void);
};

