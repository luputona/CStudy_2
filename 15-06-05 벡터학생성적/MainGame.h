#pragma once
class CStudent;

class CMainGame
{
private:
	vector<CStudent*> m_pVec;
public:
	void Initialize();
	void Progress();
public:
	void Insert();
	void Delete();
	void Render();
	void Search();
	void Sort();
	void Modify();
public:
	CMainGame(void);
	~CMainGame(void);
};

