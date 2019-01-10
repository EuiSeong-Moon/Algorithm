#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
bool cmp(pair<int, double> a, pair<int, double> b) {
	if (a.second == b.second)
		return a.first < b.first;
	else
		return a.second > b.second;
}
vector<int> solution(int N, vector<int> stages) {
	int clear = 0;
	int people = stages.size();

	int *st_num = new int[N+1];
	for (int i = 0; i < N+1; i++)
	{
		st_num[i] = 0;
	}
	for (int i = 0; i < stages.size(); i++)
	{
		st_num[stages.at(i) - 1]++;
	}
	vector<pair<int, double>> data;
	for (int i = N; i >= 0; i--)
	{
		clear += st_num[i];
		if (i != N)
		{
			if (clear == 0)
			{
				pair<int, double> p(i + 1,0);
				data.push_back(p);
			}
			else {
				pair<int, double> p(i + 1, (double)st_num[i] / (double)clear);
				data.push_back(p);
			}
		}
	}
	sort(data.begin(), data.end(), cmp);
	vector<int> answer;
	for (int it =0; it <data.size(); it++)
		answer.push_back(data.at(it).first);
	return answer;
}
int main(void)
{
	vector<int> d;
	d.push_back(4);
	d.push_back(4);
	d.push_back(4);
	d.push_back(4);
	d.push_back(4);
	solution(4, d);
}