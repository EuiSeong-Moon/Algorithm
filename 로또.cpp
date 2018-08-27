#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
	while (1)
	{
		int k;
		cin >> k;
		if (k != 0)
		{
			int *line = new int[k];
			int buf;
			for (int i = 0; i < k; i++)
			{
				cin >> buf;
				line[i] = buf;
			}

			vector<vector<int>> answer;
			vector<int> index;
			vector<int> barket;
			if (k > 5)
			{
				int i = 0;
				int j = 1;
				int flag = 0;
				while (flag==0)
				{
					barket.push_back(line[i]);
					index.push_back(i);
					if (barket.size() == 6)
					{
						answer.push_back(barket);
						barket.pop_back();
						int tm = index.at(index.size() - 1);
						index.pop_back();
						if (tm == k - j)
						{
							j++;
							while (1) {
								if (barket.size() == 0)
								{
									flag = 1;
									break;
								}
								if (index.at(index.size() - 1) == k - j)
								{
									barket.pop_back();
									index.pop_back();
									j++;
								}
								else
								{
									j = 1;
									i = index.at(index.size() - 1);
									barket.pop_back();
									index.pop_back();
									break;
								}
							}
						}
					}
					i++;
				}
				for (int n = 0; n < answer.size(); n++)
				{
					cout << answer.at(n).at(0) << " " << answer.at(n).at(1) << " " << answer.at(n).at(2) << " " << answer.at(n).at(3) << " " << answer.at(n).at(4) << " " << answer.at(n).at(5) << endl;
				}
			}
			cout << endl;
		}
		else
			return 0;
	}
	return 0;
}