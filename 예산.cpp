#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int check(int mid,int N,vector<int> area) {
	int sum = 0;
	for (int i = 0; i < N; i++)
	{
		if (area.at(i) < mid)
			sum += area.at(i);
		else
			sum += mid;
	}
	return sum;
}
int main(void)
{
	int N, buf, limit,sum=0;
	vector<int> area;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> buf;
		area.push_back(buf);
		sum += buf;
	}
	cin >> limit;
	sort(area.begin(), area.end());
	if (sum < limit)
		cout << area.at(area.size() - 1) << endl;
	else {
		int answer = 0;
		int left = 1;
		int right = area.at(area.size() - 1);
		int mid, mid2 = 0;
		while (left <= right) {
			mid = (left + right) / 2;
			int data = check(mid, N, area);
			if (data > limit)
			{
				right = mid - 1;
			}
			else if (data < limit)
			{
				left = mid + 1;
			}
			else
			{	//중간에 바로 찾은 경우 mid가 정답
				answer = mid;
				break;
			}
		}
		//끝까지 못찾은 경우 right값이 정답
		if (answer == 0)
			cout << right << endl;
		else
			cout << mid << endl;
	}
	return 0;
}