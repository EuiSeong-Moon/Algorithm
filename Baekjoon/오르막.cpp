#include<iostream>


using namespace std;

int main(void) {
	int N,before=-2000000000;
	do{
		cin >> N;
		if (before <= N) {
			before = N;
		}
		else
		{
			cout << "Bad" << endl;
			return 0;
		}

	} while (getc(stdin) == ' ');
	cout << "Good" << endl;
	return 0;
}