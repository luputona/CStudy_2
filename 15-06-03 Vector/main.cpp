#include <iostream>
#include <vector>
using namespace std;

//자료구조 스택 
//스탠다드 라이브러리 템플릿   스택하고 비슷한데 공간을 할당한다
//


void main()
{
	vector<int> m_nVec;

	m_nVec.push_back(10);
	m_nVec.push_back(20);
	m_nVec.push_back(30);
	m_nVec.push_back(40);
	m_nVec.push_back(50);

	//stl 이터레이터 


	//vector<int>::iterator iter;

	//iter = m_nVec.begin();

	//cout << *iter<<endl;
	//iter++;
	//cout << *iter <<endl;
	//--iter;
	//cout <<*iter<<endl;



	//for (iter = m_nVec.begin(); iter != m_nVec.end(); ++iter ) //클래스라 전위가 더 빠르다
	//{
	//	cout << *iter << endl;
	//}



	//cout <<"벡터 0 : "<< m_nVec[0] <<endl;




}


