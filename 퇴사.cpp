#include <iostream>

using namespace std;
int push(int profit, int day, int* profits, int* efforts, int N);
int main(void)
{
	int N;
	cin >> N;
	int *profits = new int[N];
	int *efforts = new int[N];
	int buf, buf2;
	for (int i = 0; i < N; i++)
	{
		cin >> buf >> buf2;
		profits[i] = buf2;
		efforts[i] = buf;
	}
	int real_answer = 0;
	for (int i = 0; i < N; i++)
	{
		int answer = push(0, i, profits, efforts, N);
		if (real_answer < answer)
			real_answer = answer;
	}
	cout << real_answer;
	return 0;
}
int push(int profit,int day,int* profits,int* efforts,int N)	//넣었을때 안넣었을때 다체크
{
	if (day >= N)
		return profit;
	int d = day;
	day += efforts[d];
	if(day<=N)
		profit += profits[d];
	int data=0,data2;
	if (day >= N)
		return profit;
	else {
		for (int i = 0; i+day < N; i++)//for문을 통해서 다음 꺼 다다음꺼 다다다음꺼... 넣은 경우 모두 체크
		{
			data2= push(profit, day +i, profits, efforts, N);
			if (data < data2)
				data = data2;
		}
		return data;
	}

}