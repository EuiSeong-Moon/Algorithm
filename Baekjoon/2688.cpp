#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// �̹� ���� �����ϴ����� üũ�Ͽ� ������ �������� Ȥ�� �ڱ��ڽ��� ����Ű���� ���� üũ
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
// DFS�� �� ���鼭 �ϳ��� ������ �������� �׷� ����
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
		//�ִ� ���� �������� �����ϴ� �� ä��, 1 1�� ���� �ڱ��ڽŰ� �Ʒ��� �����Ŵ� �Ʒ��� �ߺ������� ����
		if (output < (b = DFS(i, second, barket)) && b!=1)
		{
			output = b;
			answer.clear();
			for (int j = 0; j < barket.size(); j++)
				answer.push_back(barket.at(j));
		}
		if (b == 1)
			overlab.push_back(barket.at(0));

		//�� �׷� �̻� ������ ��� �����ֱ�
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
	//1 1,2 2�� ���� �ڽŰ� �Ʒ� ���� ���� ���� ������ �����ϹǷ� �߰����ֱ�
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