#include <iostream>
#include<cmath>
using namespace std;

int main(void) {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int L, U,answer=0;
		cin >> L >> U;
		
		for (int n = L; n <= U; n++) {
			int num_m = (int)sqrt((double)n);
			int count = 0;
			for (int k = 1; k <= num_m; k++) {
				if (n%k == 0)
				{
					count += 2;
				}
			}
			if (pow(num_m, 2) == n)
				count -= 1;
			if (count > answer)
				answer = count;
		}
		cout << answer << endl;
	}
	return 0;
}