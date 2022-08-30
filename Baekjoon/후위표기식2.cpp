#include<iostream>
#include<stack>
#include<string>
#include<vector>
using namespace std;
int main(void) {
	int N;
	double buf;
	cin >> N;
	string str;
	vector<double> num;
	stack<double> data;
	stack<char> operators;
	cin >> str;
	for (int i = 0; i < N; i++) {
		cin >> buf;
		num.push_back(buf);
	}
	int k=0;
	for (int i = 0; i < str.size(); i++) {
		if (isalpha(str.at(i))) {
			int buf = (int)str.at(i);
			buf -= 65;
			data.push(num.at(buf));
		}
		else {
			double d1 = data.top();
			data.pop();
			double d2 = data.top();
			data.pop();
			if (str.at(i) == '+') {
				data.push(d1 + d2);
			}
			else if (str.at(i) == '-') {
				data.push(d2 - d1);
			}
			else if (str.at(i) == '*') {
				data.push(d2*d1);
			}
			else if (str.at(i) == '/') {
				data.push(d2 / d1);
			}
		}
	}
	//소수점 둘째자리 고정하는법 precision하면 전체 다합쳐서 2자리수 fixed위에쓰면 소수점에만 적용되서 소수점 둘째자리
	cout << fixed;
	cout.precision(2);
	cout << data.top() << endl;
	return 0;
}