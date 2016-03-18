#pragma once

class CObj;

template <typename T>

class CObjFactory
{
public:
	static CObj* CreateObj()
	{
		CObj* pObj = new T;
		pObj->Initialize();
		return pObj;
	}
};