#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	int N;
	int buf;
	int answer = 5;
	vector<int> arr;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> buf;
		arr.push_back(buf);
	}
	sort(arr.begin(), arr.end());

	for (int i = 0; i < arr.size(); i++)
	{
		int scope = arr.at(i) + 4;
		int count = 1;
		for (int j = 1; j < 5; j++)
		{
			if (i + j < arr.size())
			{
				if (arr.at(i + j) <= scope)
					count += 1;
			}
		}
		count = 5 - count;
		if (answer > count)
			answer = count;
	}
	cout << answer;
	return 0;
}