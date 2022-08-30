#include <iostream>
#include <vector>

using namespace std;
int datas[11];
int operators[10];
int flag[10] = { 0, };
vector<int> ans;
int calculator(int N) {
	int answer = datas[0];
	for (int i = 0; i < N-1; i++)
	{
		int b = datas[i + 1];
		int c = ans.at(i);
		if (c == 1)
		{
			answer += b;
		}
		else if (c == 2) {
			answer -= b;
		}
		else if (c == 3) {
			answer *= b;
		}
		else if (c == 4) {
			answer /= b;
		}
		else
			cout << "eroor" << endl;
	}
	return answer;
}
void recur(int size,int N,int& min, int& max) {
	if (size == N - 1)
	{
		int answer = calculator(N);
		if (answer < min)
			min = answer;
		if (answer > max)
			max = answer;
	}
	else {
		for (int i = 0; i < N - 1; i++)
		{
			if (flag[i] == 0)
			{
				flag[i] = 1;
				ans.push_back(operators[i]);
				size++;
				recur(size, N,min,max);
				flag[i] = 0;
				ans.pop_back();
				size--;
			}
		}
	}
}
int main(void)
{
	int N,buf,min=1000000000,max=-1000000000;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin>>buf;
		datas[i] = buf;
	}
	int j = 0;
	for (int i = 0; i < 4; i++)
	{
		cin >> buf;
		while (buf != 0)
		{
			if (i == 0)
				operators[j++] = 1;
			else if (i == 1)
				operators[j++] = 2;
			else if (i == 2)
				operators[j++] = 3;
			else
				operators[j++] = 4;
			buf--;
		}
	}
	recur(0, N, min, max);
	cout << max << endl;
	cout << min << endl;
	return 0;
}