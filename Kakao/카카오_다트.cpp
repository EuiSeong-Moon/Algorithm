#include <string>
#include <vector>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <iostream>
using namespace std;

int solution(string dartResult) {
	int answer = 0;
	vector<int> point;
	for (int i = 0; i<dartResult.size(); i++)
	{
		if (dartResult.compare(i, 1, "S") == 0)
		{
			if (dartResult.at(i - 1) - '0' == 0 && i >= 2 && dartResult.at(i - 2) - '0' == 1)
				point.push_back(10);
			else
				point.push_back(dartResult.at(i - 1) - '0');
		}
		else if (dartResult.compare(i, 1, "D") == 0)
		{
			if (dartResult.at(i - 1) - '0' == 0 && i >= 2 && dartResult.at(i - 2) - '0' == 1)
				point.push_back(100);
			else
				point.push_back(pow((dartResult.at(i - 1) - '0'), 2));
		}
		else if (dartResult.compare(i, 1, "T") == 0)
		{
			if (dartResult.at(i - 1) - '0' == 0 && i >= 2 && dartResult.at(i - 2) - '0' == 1)
				point.push_back(1000);
			else
				point.push_back(pow((dartResult.at(i - 1) - '0'), 3));
		}
		else if (dartResult.compare(i, 1, "*") == 0)
		{
			point.at(point.size() - 1) *= 2;
			if (point.size() >= 2)
				point.at(point.size() - 2) *= 2;
		}
		else if (dartResult.compare(i, 1, "#") == 0)
		{
			point.at(point.size() - 1) *= -1;
		}
	}
	for (int i = 0; i<point.size(); i++)
		answer += point.at(i);
	return answer;
}

int main(void)
{
	return 0;
}