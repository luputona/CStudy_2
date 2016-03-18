#pragma once
#include "Obj.h"

class CBitMap;
class CMapEdit : public CObj
{
private:
	vector<TILE*>		m_vecTile;
	vector<CBitMap*>	m_vecBmp;
	float m_fScrollX;
	float m_fScrollY;
	float m_fSpeed;
	bool m_bIDCheck;
public:
	void InitTile(void);
	TILE* CreateTile(float _fx, float _fy);
	void Picking();
	void CheckKey();
	void Scroll();
public:
	virtual void Initialize();
	virtual void Progress();
	virtual void Render(HDC hdc);
	virtual void Release();

public:
	CMapEdit(void);
	~CMapEdit(void);
};

