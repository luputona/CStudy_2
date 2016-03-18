#pragma once

class CObj;


template <typename T>
class CObjFactory
{
public:
	static inline CObj* CreateObj()
	{
		CObj* pObj = new T;
		pObj->Initialize();
		return pObj;
	}

	static inline CObj* CreateObj(float _fx, float _fy, float _fAngle)
	{
		CObj* pObj = new T;
		pObj->Initialize();
		pObj->SetPos(_fx,_fy);
		
		((CBullet*)pObj)->SetAngle(_fAngle);

		return pObj;
	}


public:
	CObjFactory(void);
	~CObjFactory(void);
};

