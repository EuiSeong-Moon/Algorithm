#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int solution(int cacheSize, vector<string> cities) {
	int answer = 0;
	vector<string> cache_barket;
	vector<int> recent_use;
	string str;
	int sz = 0;
	for (int i = 0; i<cities.size(); i++)
	{
		int t;
		int cache_flag = -1;
		for (int j = 0; j<cities.at(i).size(); j++)
			cities.at(i).at(j) = toupper(cities.at(i).at(j));
		for (t = 0; t<cache_barket.size(); t++)
		{
			if (cache_barket.at(t) == cities.at(i))
			{
				cache_flag = t;
				break;
			}
		}
		if (cache_flag == -1)
		{
			answer += 5;
			if (sz<cacheSize)
			{
				cache_barket.push_back(cities.at(i));
				recent_use.push_back(cache_barket.size() - 1);
				sz++;
			}
			else if(sz!=0)
			{
				int k = 0;
				while (1)
				{
					if (recent_use.at(k) != -1)
					{
						k = recent_use.at(k);
						break;
					}
					k++;
				}
				cache_barket.at(k) = "";
				recent_use.at(k) = -1;
				cache_barket.push_back(cities.at(i));
				recent_use.push_back(cache_barket.size() - 1);
			}
		}
		else
		{
			answer += 1;
			cache_barket.at(cache_flag) = "";
			recent_use.at(cache_flag) = -1;
			cache_barket.push_back(cities.at(i));
			recent_use.push_back(cache_barket.size() - 1);
		}
	}
	return answer;
}
int main(void)
{
	vector<string> str;
	str.push_back("Jeju");
	str.push_back("Pangyo");
	str.push_back("Seout");
	str.push_back("NewYork");
	str.push_back("LA");
	str.push_back("Jeju");
	str.push_back("Pangyo");
	str.push_back("Seoul");
	str.push_back("NewYork");
	str.push_back("LA");
	int answer=solution(3, str);
	cout << answer;
	return 0;
}