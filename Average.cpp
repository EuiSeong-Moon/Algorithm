#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

int main(void)
{
	int N, maxindex = 0;
	double sum=0,max=0;
	vector<double> barket;
	cin >> N;
	
	for (int i = 0; i < N; i++)
	{
		int a;
		cin >> a;
		if (max < a)
		{
			max = a;
			maxindex = i;
		}
		barket.push_back(a);
	}
	for (int i = 0; i < barket.size(); i++)
	{
		barket.at(i) = (barket.at(i) / max * 100) ;
		sum += barket.at(i);
	}
	sum = round((sum / barket.size()) * 100) / 100;
	cout << fixed;
	cout.precision(2);
	cout << sum;
}