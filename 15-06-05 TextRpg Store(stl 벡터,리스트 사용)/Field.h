#pragma once

class CObj;


class CField
{
private:
	CObj *m_pPlayer;
	//CObj *m_pMonster;

	list <CObj*> m_pMonList;
public:
	void Progerss();
	void DrawMap();
	void CreateMonster(int nInput);
	void Fight();

public:
	void SetPlayer(CObj *pPlayer)
	{
		m_pPlayer = pPlayer;
	}
public:
	CField(void);
	~CField(void);
};

