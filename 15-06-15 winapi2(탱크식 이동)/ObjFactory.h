#pragma once

class CObj;
template<typename T>
class CObjFactory
{
public:
	static inline CObj* CreateObj()
	{
		CObj* pObj = new T;
		pObj->Initialize();

		return pObj;
	}

public:
	CObjFactory(void);
	~CObjFactory(void);
};

