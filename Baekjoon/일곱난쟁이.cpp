#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	int buf;
	vector<int> height;
	for (int i = 0; i < 9; i++)
	{
		cin >> buf;
		height.push_back(buf);
	}
	//int flag[9] = { 1,1,1,1,1,1,1,0,0 };
	vector<int> sum;
	int i = 0,answer=0;
	while (1)
	{
		if (sum.size() != 7)
		{
			sum.push_back(height.at(i));
		}
		else
		{
			for (int j = 0; j < sum.size(); j++)
			{
				answer += sum.at(j);
			}
			if (answer == 100)
				break;
			answer = 0;
			if (i <= 8)
			{
				sum.pop_back();
				sum.push_back(height.at(i));
			}
			else
			{
				int k;
				do {
					sum.pop_back();
					for (k = 0; k < height.size(); k++)
					{
						if (sum.at(sum.size() - 1) == height.at(k))
							break;
					}
					//sum.pop_back();
				} while (k == sum.size() + 1);
				sum.pop_back();
				i = k;
			}
		}
		i++;
	}
	sort(sum.begin(), sum.end());
	for (int j = 0; j < sum.size(); j++)
		cout << sum.at(j) << endl;
	return 0;
}