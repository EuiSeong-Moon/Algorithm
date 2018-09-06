#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iostream>
using namespace std;
vector<string> solution(int n, vector<int> arr1, vector<int> arr2);
int main(void)
{
	vector<int> arr1;
	vector<int> arr2;
	int n = 5;
	arr1.push_back(9);
	arr1.push_back(20);
	arr1.push_back(28);
	arr1.push_back(18);
	arr1.push_back(11);
	arr2.push_back(30);
	arr2.push_back(1);
	arr2.push_back(21);
	arr2.push_back(17);
	arr2.push_back(28);
	vector<string> str=solution(n, arr1, arr2);
	for (int i = 0; i < str.size(); i++)
		cout << str.at(i) << endl;
}

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
	vector<string> answer;
	for (int i = 0; i<n; i++)
	{
		int data = arr1.at(i) | arr2.at(i);
		string str;
		int k = 1;
		while (n - k >= 0)
		{
			if (data >= pow(2, (n - k)))
			{
				str.push_back('#');
				data -= pow(2, (n - k));
			}
			else
				str.push_back(' ');
			k++;
		}
		answer.push_back(str);
	}
	return answer;
}