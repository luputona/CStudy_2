#pragma once

class CPlayer;
class CMonster;

class CField
{
private:
	CPlayer *m_pPlayer;
	CMonster *m_pMonster;
public:
	void Progerss();
	void DrawMap();
	void CreateMonster(int nInput);
	void Fight();

public:
	void SetPlayer(CPlayer *pPlayer)
	{
		m_pPlayer = pPlayer;
	}
public:
	CField(void);
	~CField(void);
};

