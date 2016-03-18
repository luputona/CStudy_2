#pragma once
class CBall;
class CMainGame
{
private:
	CBall* m_pBall;
public:
	void Initialize();
	void Progress();
	void Render();
	void Release();
public:
	CMainGame(void);
	~CMainGame(void);
};

