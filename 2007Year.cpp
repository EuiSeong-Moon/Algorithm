#include<iostream>

using namespace std;

int main(void)
{
	int x, y;
	cin >> x>> y;
	int month[12] = { 31, 28, 31,  30,  31, 30,  31,  31,30,  31,  30,31 };
	int sum = 0;
	for (int i = 1; i < x; i++)
		sum += month[i-1];
	sum += y;
	sum %= 7;
	switch (sum)
	{
	case 1:
		cout << "MON" << endl;
		break;
	case 2:
		cout << "TUE" << endl;
		break;
	case 3:
		cout << "WED" << endl;
		break;
	case 4:
		cout << "THU" << endl;
		break;
	case 5:
		cout << "FRI" << endl;
		break;
	case 6:
		cout << "SAT" << endl;
		break;
	case 0:
		cout << "SUN" << endl;
		break;
	default:
		cout << "¿À·ù" << endl;
	}
}