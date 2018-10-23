#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main(void)
{
	string num;
	cin >>  num;
	unordered_map<char,int> hook;
	int max = 0,sz;
	for (int i = 0; i < num.size(); i++)
	{
		if (num.at(i) == '9')
			num.at(i) = '6';
		hook[num.at(i)]++;
		if (num.at(i) == '6')
		{
			int t = hook[num.at(i)] / 2;
			if (hook[num.at(i)] % 2 != 0)
				t++;
			sz = t;
		}
		else
			sz = hook[num.at(i)];
		if (sz > max)
			max = sz;
	}
	cout << max;
	return 0;
}