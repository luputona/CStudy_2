#include <iostream>
#include <map>
#include <string>
using namespace std;



void main()
{
	//자료구조의 맵을 쉽게 쓰라고 만들어논stl
	//맵은 트리구조 키값,데이타

	 //map<int,int> m_Map;

	 //m_Map.insert(pair<int,int>(5,100));
	 //m_Map.insert(make_pair(3,800));
	 //m_Map.insert(map<int,int>::value_type(4,1));
	 //m_Map.insert(make_pair(2,10));
	 //m_Map.insert(make_pair(1,2000));


	 //map<int,int>::iterator iter = m_Map.begin();

	 //for (iter = m_Map.begin(); iter != m_Map.end(); ++iter)
	 //{
		// cout<<iter->first <<"\t"<<iter->second<<endl;
	 //}
	 


	 map<int,int,greater<int>> m_Map1;
	 

	 //인덱스가 아닌 키값
	 m_Map1[5] = 100;
	 m_Map1[4] = 200;
	 m_Map1[2] = 300;
	 m_Map1[1] = 400;
	 m_Map1[3] = 500;

	 for (int i = 1; i<6; i++)
	 {
		 cout << m_Map1[i]<<endl;
	 }

	 map<int,int,greater<int>>::iterator iter;

	 for (iter = m_Map1.begin(); iter != m_Map1.end(); ++iter)
	 {
		 cout<<iter->first<<"\t"<<iter->second<<endl;
	 }

	 cout <<"=============================\n";

	 m_Map1[5] = 200;

	 for (iter = m_Map1.begin(); iter != m_Map1.end(); ++iter)
	 {
		 cout<<iter->first<<"\t"<<iter->second<<endl;
	 }



}

