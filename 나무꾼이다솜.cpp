#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	int N, C, W;
	int answer = 0;
	cin >> N >> C >> W;
	vector<int> barket;
	int buf;
	for (int i = 0; i < N; i++)
	{
		cin >> buf;
		barket.push_back(buf);
	}
	sort(barket.begin(), barket.end());
	int count = 1;
	//0�� �߶�����
	for (int i = 0; i < barket.size(); i++)
	{
		if (i != (barket.size() - 1) && barket.at(i + 1) == barket.at(i))
		{
			count++;
		}
		else if (count != 1)
		{
			if (answer < count*barket.at(i)*W)
				answer = count*barket.at(i)*W;
			count = 1;
		}
		else {
			if(answer < barket.at(i)*W)
				answer = barket.at(i)*W;
			count = 1;
		}
	}
	// �߶�����
	for (int i = 1; i <= barket.at(barket.size()-1); i++)
	{
		int answer_buf = 0;
		for (int j = 0; j < barket.size(); j++)
		{
			int num = 0;
			int num2 = 0;
			num += int(barket.at(j) / i);
			num2 += int(barket.at(j) / i);
			if (barket.at(j) % i == 0)
				num2 -= 1;
			if(num*W*i-num2*C>0)	// i������ �������� �ڸ���, �Ϻδ� �ڸ��� �Ϻδ� ���ڸ��� ��찡 ���� �� ���� �� ��츦 üũ���ִ� �κ��ε� �̰� �������߾���.
				answer_buf+= num*W*i - (num2*C);
		}
		//int answer_buf = num*W*i - (num2*C);
		if (answer < answer_buf)
			answer = answer_buf;
	}
	cout << answer;
	return 0;
}