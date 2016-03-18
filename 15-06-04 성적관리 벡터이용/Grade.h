#pragma once

#include <string>

class CGrade
{
private:
	string m_strName;
	string m_strGrade;
	int m_nKor;
	int m_nEng;
	int m_nMath;
	int m_nTotal;
	float m_fAvg;
public:
	void SetInfo(string _Name,int _nKor,int _nEng,int _nMath);
	void InputInfo();
	void Output();
public:
	CGrade(void);
	~CGrade(void);
};

