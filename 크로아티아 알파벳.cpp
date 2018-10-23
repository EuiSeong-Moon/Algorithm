#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(void)
{
	string data;
	cin >> data;
	int count = 0;
	for (int i = 0; i < data.size(); i++)
	{
		if (data.at(i) == 'c')
		{
			if (i != data.size() - 1 && (data.at(i + 1) == '=' || data.at(i + 1) == '-'))
			{
				count++;
				i++;
				continue;
			}
		}
		else if (data.at(i) == 'd')
		{
			if (i != data.size() - 1 && data.at(i + 1) == '-')
			{
				count++;
				i++;
				continue;
			}
			else if (i < data.size() - 2 && data.at(i + 1) == 'z' && data.at(i + 2) == '=')
			{
				count++;
				i+=2;
				continue;
			}
		}
		else if (data.at(i) == 'l' || data.at(i)=='n')
		{
			if (i != data.size() - 1 && data.at(i + 1) == 'j')
			{
				count++;
				i++;
				continue;
			}
		}
		else if (data.at(i) == 's' || data.at(i)=='c' || data.at(i)=='z'){
			if (i != data.size() - 1 && data.at(i + 1) == '=')
			{
				count++;
				i++;
				continue;
			}
		}
		count++;
	}
	cout << count;
	return 0;
}