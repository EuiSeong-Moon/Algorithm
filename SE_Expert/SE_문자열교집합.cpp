#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;


int main(void)
{
	string a, b;
	int test = 0,count=0;
	cin >> test;
	for (int i = 0; i < test; i++)
	{
		count = 0;
		unordered_set<string> s;
		//hash_set<string>::iterator k;
		int m, n;
		cin >> m >> n;
		for (int i = 0; i < m; i++)
		{
			cin >> a;
			s.insert(a);
		}
		for (int i = 0; i < n; i++)
		{
			cin >> b;
			if (s.find(b) != s.end())
				count++;
		}
		cout <<"#"<< i + 1 << " " << count<<endl;
	}
	return 0;
}