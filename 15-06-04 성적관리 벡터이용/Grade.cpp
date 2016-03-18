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
	cout << "이름 입력 : ";
	cin >> m_strName;
	cout <<"국어점수 : ";
	cin >>m_nKor;
	cout <<"영어점수 : ";
	cin >> m_nEng;
	cout <<"수학점수 : ";
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


	cout << "이름 : "<<m_strName<<endl;
	cout <<"국어 : "<<m_nKor<<endl;
	cout <<"영어 : "<<m_nEng<<endl;
	cout <<"수학 : "<<m_nMath<<endl;
	cout <<"총점 : "<<m_nTotal<<endl;
	cout <<"평균 : "<<m_fAvg<<endl;
	cout <<"등급 : "<<m_strGrade<<endl;
}
