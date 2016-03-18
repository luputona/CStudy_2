#include <iostream>
#include <list>
using namespace std;
#include <vector>
#include <algorithm>
#include <map>



bool Greater(int a, int b)
{
	return a>b;
}

bool Less(int a,int b)
{
	return a<b;
}

void main()
{
	//list<int> m_List1;
	//list<int> m_List2;


	//for (int i = 0;i<5; ++i)
	//{
	//	m_List1.push_back(i * 10);
	//}

	//for (int i = 0;i<5; ++i)
	//{
	//	m_List2.push_back(i * 100);
	//}

	//list<int>::iterator iter;
	//for (iter = m_List1.begin(); iter != m_List1.end(); ++iter)
	//{
	//	cout << (*iter)<<endl;
	//}

	//for (iter = m_List2.begin(); iter != m_List2.end(); ++iter)
	//{
	//	cout << (*iter)<<endl;
	//}


	//자료구조 리스트
	

	//list<int>::iterator iter = m_List.begin();

	//m_List.reverse();

	//for (iter = m_List.begin(); iter != m_List.end(); ++iter)
	//{
	//	cout <<(*iter)<<endl;
	//}

	/*m_List.pop_back();
	m_List.pop_back();
	m_List.pop_back();
*/
	/*cout <<endl;

	for (iter = m_List.begin(); iter != m_List.end(); ++iter)
	{
		cout <<(*iter)<<endl;
	}
*/
	//cout<<"============================================\n";

	//list<int>::iterator iter = m_List.begin();

	//++iter;
	//++iter;
	//++iter;
	//--iter;
	//--iter;

	//cout<<(*iter)<<endl;

	//(*iter) = 10;

	//cout <<(*iter)<<endl;
	//cout <<endl;

	//for (iter = m_List.begin(); iter != m_List.end(); ++iter)
	//{
	//	cout <<(*iter)<<endl;
	//}





	list<int> m_List;

	m_List.push_back(10);
	m_List.push_back(20);
	m_List.push_back(30);
	m_List.push_back(40);
	m_List.push_back(50);

	m_List.sort(Less); //greater 큰수부터 정렬 , less 작은수부터 정렬

	for (list<int>::iterator iter = m_List.begin(); iter != m_List.end(); ++iter)
	{
		cout<< (*iter) <<endl;
	}



	/*vector<int> m_nVec;

	for (int i = 1; i<11; i++)
	{
		m_nVec.push_back(rand() % 11);
	}
	
	sort(m_nVec.begin(),m_nVec.end(),greater<int>());

	for (size_t i = 0; i<m_nVec.size(); ++i)
	{
		cout<<m_nVec[i]<<"\t";
	}*/

}




