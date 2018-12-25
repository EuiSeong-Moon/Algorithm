#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main(void)
{
	unordered_map<char,int> m_map;
	string flag = "abcdefghijklmnopqrstuvwxyz";
	string str;
	cin >> str;
	for (int i = 0; i < 26; i++)
	{
		m_map[flag.at(i)] = -1;
	}
	for (int i = 0; i < str.size(); i++)
	{
		if(m_map[str.at(i)]==-1)
			m_map[str.at(i)] = i;
	}
	
	for (int i = 0; i < 26; i++)
	{
		cout << m_map[flag.at(i)] << " ";
	}
	return 0;
}