#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 이미 값이 존재하는지를 체크하여 문법상 정상인지 혹은 자기자신을 가리키는지 등을 체크
int index_finding(vector<int> a,int target)
{
	for (int i = 0; i < a.size(); i++)
	{
		if (a.at(i) == target && i == 0)
			return 1;
		if(a.at(i)==target)
			return -1;
		if(i==a.size()-1)
			return 0;
	}
}
// DFS를 쭉 돌면서 하나의 문법상 정상적인 그룹 생성
int DFS(int index, int* arr,vector<int>& barket)
{
	int mid,flag,len = 0;
	barket.clear();
	while (1)
	{
		mid = arr[index];
		//barket check
		if (barket.size() != 0) {
			if ((flag = index_finding(barket, mid)) == 0)
				barket.push_back(index);
			if (flag == -1)
				return -1;
			if (flag == 1)
			{
				barket.push_back(index);
				return len + 1;
			}
		}
		
		else
			barket.push_back(index);
		len += 1;
		if (mid == index && len == 1)
			return 1;
		index = mid;
	}
}

int main(void)
{
	int N,output=0,b;
	int* second;
	vector<int> barket;
	vector<int> answer;
	vector<int> overlab;
	//input
	cin >> N;
	second = new int[N + 1];
	for (int i = 1; i < N + 1; i++)
		cin >> second[i];

	for (int i = 1; i < N + 1; i++)
	{
		//최대 값을 바탕으로 성립하는 거 채택, 1 1과 같이 자기자신과 아래가 같은거는 아래서 중복됨으로 제외
		if (output < (b = DFS(i, second, barket)) && b!=1)
		{
			output = b;
			answer.clear();
			for (int j = 0; j < barket.size(); j++)
				answer.push_back(barket.at(j));
		}
		if (b == 1)
			overlab.push_back(barket.at(0));

		//두 그룹 이상 정답인 경우 더해주기
		else if (b != -1)
		{
			for (int k = 0; k < barket.size(); k++)
			{
				if (index_finding(answer, barket.at(k)) == 0)
				{
					answer.push_back(barket.at(k));
					output += 1;
				}
			}
		}
	}
	//1 1,2 2와 같이 자신과 아래 값이 같은 경우는 무조건 가능하므로 추가해주기
	for (int i = 0; i < overlab.size(); i++)
	{
		answer.push_back(overlab.at(i));
		output += 1;
	}
	cout << output << endl;
	sort(answer.begin(), answer.end());
	for (int i = 0; i < answer.size(); i++)
		cout << answer.at(i)<<endl;
	free(second);
	return 0;
}