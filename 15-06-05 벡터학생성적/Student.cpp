#include "StdAfx.h"
#include "Student.h"


CStudent::CStudent(void)
{
}


CStudent::~CStudent(void)
{
}

void CStudent::Input()
{
	cout <<"�̸� �Է� :";
	cin >> m_tStudent.strName;
	cout <<endl;

	cout <<"���� �Է� :";
	cin >> m_tStudent.nKor;
	cout <<endl;

	cout <<"���� �Է� :";
	cin >> m_tStudent.nEng;
	cout <<endl;

	cout <<"���� �Է� :";
	cin >> m_tStudent.nMath;
	cout <<endl;
	


}

void CStudent::Output()
{
	cout << "�̸�\t����\t����\t����\t����\t���\t"<<endl;
	cout<<m_tStudent.strName<<"\t"<<m_tStudent.nKor<<"\t"<<m_tStudent.nEng<<"\t"<<m_tStudent.nMath<<"\t";
	cout <<m_tStudent.nTotal<<"\t"<<m_tStudent.fAvg<<endl;

}

void CStudent::Sum()
{
	m_tStudent.nTotal = m_tStudent.nKor + m_tStudent.nEng + m_tStudent.nMath;
	m_tStudent.fAvg =  float(m_tStudent.nTotal)/3.f;
}
