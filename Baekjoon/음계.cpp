#include <iostream>
#include <string>
using namespace std;

int main(void)
{
	string ups = "ascending";
	string downs = "descending";
	string others = "mixed";
	int number = 0;
	int before = 0;
	int current;
	for (int i = 0; i < 8;i++)
	{
		cin >> current;
		if ((current - before) == 1) { number += 1; }
		if (i == 0 && (current - before) == 8) { number -= 1; }
		if (i != 0 && (current - before == -1)) { number-= 1; }
		before = current;
	}
	switch (number)
	{
	case 8:
		cout << ups << endl;
		break;
	case -8:
		cout << downs << endl;
		break;
	default:
		cout << others << endl;
		break;
	}
	return 0;
}