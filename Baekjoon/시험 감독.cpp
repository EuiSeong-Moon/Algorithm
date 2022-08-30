#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
	int N, buf, B, C;
	long long answer = 0;
	vector<int> room;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> buf;
		room.push_back(buf);
	}
	cin >> B >> C;
	for (int i = 0; i < N; i++)
	{
		answer += 1;
		room.at(i) -= B;
		if (room.at(i) > 0)
		{
			if (room.at(i) % C == 0)
			{
				answer += room.at(i) / C;
			}
			else {
				answer += room.at(i) / C+1;
			}
		}
	}
	cout << answer << endl;
	return 0;
}