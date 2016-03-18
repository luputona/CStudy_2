#include "StdAfx.h"
#include "Grade.h"


CGrade::CGrade(void) :
m_nKor(0),
m_nEng(0),
m_nMath(0),
m_nTotal(0),
m_fAvg(0.0f)
{
}

CGrade::~CGrade(void)
{
}

void CGrade::InputInfo()
{
	cout << "�̸� �Է� : ";
	cin >> m_strName;
	cout <<"�������� : ";
	cin >>m_nKor;
	cout <<"�������� : ";
	cin >> m_nEng;
	cout <<"�������� : ";
	cin >> m_nMath;

}

void CGrade::SetInfo( string _Name,int _nKor,int _nEng,int _nMath )
{

}

void CGrade::Output()
{
	m_nTotal = m_nKor+m_nEng+m_nMath;
	m_fAvg = (float)m_nTotal/3;

	if (m_fAvg == 100)
	{
		m_strGrade = "A+";
	}
	else if (m_fAvg >=90)
	{
		m_strGrade = "A";
	}
	else if (m_fAvg >=80)
	{
		m_strGrade = "B";
	}
	else if (m_fAvg >= 70)
	{
		m_strGrade = "C";
	}
	else if (m_fAvg >= 60)
	{
		m_strGrade = "D";
	}
	else
		m_strGrade = "F";	


	cout << "�̸� : "<<m_strName<<endl;
	cout <<"���� : "<<m_nKor<<endl;
	cout <<"���� : "<<m_nEng<<endl;
	cout <<"���� : "<<m_nMath<<endl;
	cout <<"���� : "<<m_nTotal<<endl;
	cout <<"��� : "<<m_fAvg<<endl;
	cout <<"��� : "<<m_strGrade<<endl;
}
