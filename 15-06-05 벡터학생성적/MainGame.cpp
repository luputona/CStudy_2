#include "StdAfx.h"
#include "MainGame.h"
#include "Student.h"

CMainGame::CMainGame(void)
{
}


CMainGame::~CMainGame(void)
{
}

void CMainGame::Initialize()
{
	m_pVec.push_back(new CStudent);
	m_pVec[0]->Input();
	m_pVec[0]->Sum();
}

void CMainGame::Progress()
{
	int nInput = 0;

	while(true)
	{
		cout <<"1.�߰� 2.���� 3.��� 4.�˻� 5.���� 6.���� 7.���� : ";
		cin >>nInput;

		if (nInput == 7)
		{
			break;
		}

		switch(nInput)
		{
		case 1:
			Insert();
			break;
		case 2:
			Delete();
			break;
		case 3:
			Render();
			break;
		case 4:
			Search();
			break;
		case 5:
			Sort();
			break;
		case 6:
			Modify();
			break;
		}

	}



}

void CMainGame::Insert()
{
	int nInput = 0;
	cout << "�߰��� �л����� �Է� �ϼ��� : ";
	cin >> nInput;

	for (int i = 0; i< nInput; ++i)
	{
		m_pVec.push_back(new CStudent);
		m_pVec.back()->Input();
		m_pVec.back()->Sum();
	}
	
}

void CMainGame::Delete()
{
	string strFindName = "";
	cout <<"������ �л��� �̸��� �Է� �ϼ��� : ";
	cin >> strFindName;

	for (vector<CStudent*>::iterator iter = m_pVec.begin(); iter != m_pVec.end(); ++iter)
	{
		if ((*iter)->GetInfo().strName == strFindName )
		{
			delete (*iter);
			(*iter) = NULL;

			m_pVec.erase(iter);
			break;
		}
	}
}

void CMainGame::Render()
{
	for (size_t i =0; i<m_pVec.size(); ++i)
	{
		m_pVec[i]->Output();
	}
}

void CMainGame::Search()
{
	system("cls");
	string strFindName = "";
	cout <<"�˻��� �л��� �̸��� �Է� �ϼ��� : ";
	cin >> strFindName;

	for (vector<CStudent*>::iterator iter = m_pVec.begin(); iter != m_pVec.end(); ++iter)
	{
		if ((*iter)->GetInfo().strName == strFindName )
		{
			(*iter)->Output();
			break;
		}
	}
}
bool Greater(CStudent *a,CStudent *b)
{
	return a->GetInfo().fAvg < b->GetInfo().fAvg;
}


void CMainGame::Sort()
{
	/*for (size_t i =0; i<m_pVec.size() - 1; ++i)
	{
		for (size_t j =0; j<m_pVec.size() - i -1; ++j)
		{
			if (m_pVec[j]->GetInfo().fAvg < m_pVec[j+1]->GetInfo().fAvg)
			{
				CStudent *pStudent;

				pStudent = m_pVec[j];
				m_pVec[j] = m_pVec[j+1];
				m_pVec[j+1] = pStudent;
			}
		}
	}*/	

	sort(m_pVec.begin(),m_pVec.end(),Greater);
}

void CMainGame::Modify()
{
	string strFindName = "";
	cout <<"������ �л��� �̸��� �Է� �ϼ��� : ";
	cin >> strFindName;

	for (vector<CStudent*>::iterator iter = m_pVec.begin(); iter != m_pVec.end(); ++iter)
	{
		if ((*iter)->GetInfo().strName == strFindName )
		{
			(*iter)->Input();
			(*iter)->Output();
			break;
		}
	}
}
