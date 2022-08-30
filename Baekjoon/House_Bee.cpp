#include<iostream>

using namespace std;

int main(void)
{
	int target, count = 0,minus=6;
	cin >> target;
	while (target > 1)
	{
		target -=minus;
		minus += 6;
		++count;
	}
	cout << count+1;
	return 0;
}