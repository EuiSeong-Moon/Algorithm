#include <iostream>
#include <unordered_map>
using namespace std;
int main(void) {
	int N;
	cin >> N;
	unordered_map<int, int> map;
	for (int i = 1; i <= N; i++) {
		map[i] = -1;
	}
	int t1, t2;
	cin >> t1 >> t2;
	int line,buf1,buf2;
	cin >> line;
	for (int i = 0; i < line; i++) {
		cin >> buf1 >> buf2;
		map[buf2] = buf1;
	}
	if (t1 == t2)
	{
		cout << 0 << endl;
		return 0;
	}
	int answer=-1;
	int count1 = 0,count2=0;
	int k=t1, o=t2;
	while (k != -1 && answer==-1) {
		count2 = 0;
		o = t2;
		if (o == k)
		{
			answer = count1 + count2;
			break;
		}
		while (o != -1) {
			
			o = map[o];
			count2++;
			if (o == k)
			{
				answer = count1 + count2;
				break;
			}
		}
		k = map[k];
		count1++;
	}
	cout << answer << endl;
	return 0;
}