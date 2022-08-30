#include <iostream>
#include <algorithm>
using namespace std;


//Top-down
int knapsack(int N, int wt[], int val[],int nn)
{
	if (N == 0 || nn == -1)
		return 0;
	else if (wt[nn] > N)
		return knapsack(N, wt, val, nn - 1);
	else
		return max(knapsack(N, wt, val, nn - 1), val[nn] + knapsack(N - wt[nn], wt, val, nn));
}
//Bottom-up
int main(void)
{
	int N;
	cin >> N;
	int benefit[3001];
	int weight[3001];
	benefit[0] = 0;	 weight[0] = 0;
	for (int i = 1; i <= N; i++)
	{
		int aa;	cin >> aa;
		benefit[i] = aa;
	}
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			weight[i] = max(weight[i], weight[i - j] + benefit[j]);
		}
	}
	cout << weight[N];
	return 0;
}