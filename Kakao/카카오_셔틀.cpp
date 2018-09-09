#include <string>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <iostream>
using namespace std;
//숫자로 변화하여 크루들의 출근 시간을 정렬 후 버스 도착 시작 간격으로 계산

int flag[2001] = { 0, };
string solution(int n, int t, int m, vector<string> timetable) {
	string answer = "";
	int answer_t = 0;
	int time1 = 0, time2, time3, time4, time = 0;
	int bus_t = 540;
	vector<int> bus_f;
	vector<int> crew;
	for (int j = 0; j<timetable.size(); j++)
	{
		time1 = timetable.at(j).at(0) - '0';
		time2 = timetable.at(j).at(1) - '0';
		time3 = timetable.at(j).at(3) - '0';
		time4 = timetable.at(j).at(4) - '0';
		time = (time1 * 10 + time2) * 60 + (time3 * 10 + time4);
		crew.push_back(time);
	}
	sort(crew.begin(), crew.end());
	for (int i = 0; i<n; i++)
	{
		int sz = m;
		for (int j = 0; j<crew.size(); j++)
		{
			if (flag[j] == 0 && sz>0 && bus_t >= crew.at(j))
			{
				if (i == n - 1)
				{
					bus_f.push_back(crew.at(j));
				}
				sz--;
				flag[j] = 1;
			}
			// time=0;
		}
		if (i == n - 1)
		{
			if (sz == 0)
			{
				//sort(bus_f.begin(),bus_f.end());
				answer_t = bus_f.at(bus_f.size() - 1) - 1;
			}
			else
				answer_t = bus_t;
		}
		bus_t += t;
	}
	time1 = answer_t / 60;    time2 = time1 % 10;   time1 = time1 / 10;
	time3 = answer_t % 60;  time4 = time3 % 10; time3 = time3 / 10;
	char tt = time1 + '0';
	char tt2 = time2 + '0';
	char tt3 = time3 + '0';
	char tt4 = time4 + '0';
	// itoa(time1,tt,10);
	answer += tt; answer += tt2;  answer += ':';  answer += tt3;    answer += tt4;
	// answer+=char(time1);  answer+=char(time2);  answer+=char(time3);  answer+=char(time4);
	return answer;
}

int main(void)
{
	int n = 2;
	int t = 10;
	int m = 2;
	vector<string> str;
	str.push_back("09:10");
	str.push_back("09:09");
	str.push_back("08:00");
//	str.push_back("00:01");
//	str.push_back("00:01");
	string answer=solution(n, t, m, str);
	cout << answer;
	return 0;
}