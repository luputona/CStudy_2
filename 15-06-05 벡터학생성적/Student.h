#pragma once
#include "Define.h"


class CStudent
{
private:
	STU m_tStudent;
public:
	void Input();
	void Output();
	void Sum();
public:
	STU GetInfo() {return m_tStudent;}

public:
	CStudent(void);
	~CStudent(void);
};

