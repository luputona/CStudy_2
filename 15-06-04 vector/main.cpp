#include <iostream>
#include <vector>
using namespace std;

void main()
{
//	vector<int> m_Vec;
//
//	m_Vec.reserve(4);
//	m_Vec.push_back(10);
//	m_Vec.push_back(20);
//	m_Vec.push_back(30);
//	m_Vec.push_back(40);
//
//	m_Vec.pop_back(); //맨 뒤값을 뺄때 
//
//	for (vector<int>::size_type i =0; i<m_Vec.size(); ++i)
//	{
//		cout <<m_Vec[i]<<"\t";
//	}
//	cout << endl;
//
//
//	m_Vec.front() = 100; //첫번째의 값을 넣을때 
//	m_Vec.back() = 200; //맨뒤의 값을 넣을때 
//
//	for (vector<int>::size_type i =0; i<m_Vec.size(); ++i)
//	{
//		cout <<m_Vec[i]<<"\t";
//	}
//
//	m_Vec.clear();
//
//	cout <<endl;
//
//	if (m_Vec.empty()) //비었을때
//	{
//		cout <<"비었구나\n";
//	}
//--------------------------------------------------------


	vector<int>m_nVec(3);

	m_nVec[0] = 10;
	m_nVec[1] = 20;
	m_nVec[2] = 30;

	for (vector<int>::size_type i = 0; i<m_nVec.size(); ++i)
	{
		cout <<m_nVec[i]<<"\t";
	}

	cout <<endl;






}