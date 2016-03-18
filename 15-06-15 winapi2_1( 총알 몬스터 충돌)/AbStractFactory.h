#pragma once


class CObj;
template <typename T>
class CAbStractFactory
{
public:
	static inline CObj* CreateObj()
	{
		CObj* pObj = new T;

		pObj->Initialize();

		return pObj;
	}
public:
	CAbStractFactory(void);
	~CAbStractFactory(void);
};

