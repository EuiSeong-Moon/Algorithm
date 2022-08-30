#include<iostream>
#include<vector>
#include<string>
using namespace std;
//가장 중요한 포인트
// 1. )인경우 ( 까지 계싼
// 2. 우선순위가 더 높거나 같은것이 stack에 이미있는경우 pop해서 계산 후 연산자 push
// 3. 그 외의 경우 그냥 push하고 맨 마지막에 나머지 pop
int isOperators(string op) {
	if (op == "*" || op == "/") {
		return 2;
	}
	else if (op == "+" || op == "-") {
		return 1;
	}
	else if (op == "(" || op == ")") {
		return 0;
	}
	else {
		return -1;
	}
}
int main(void) {
	string buf;
	cin >> buf;
	vector<string> data;
	vector<string> operators;
	int flag = 0;
	for (int i = 0; i < buf.size(); i++) {
		string a(1, buf.at(i));
		if (isalpha(buf.at(i))) {
			cout << a;
		}
		else {
			int orders = isOperators(a);
			if (buf.at(i)=='(') {
				data.push_back(a);
			}
			else if (buf.at(i) == ')') {
				while (data.at(data.size() - 1) != "(") {
					string buf = data.at(data.size() - 1);
					data.pop_back();
					cout << buf;
				}
				data.pop_back();
			}
			else if (orders == 1 || orders == 2) {
				while (data.size() != 0 && isOperators(data.at(data.size() - 1)) >= orders) {	//반드시 (,),숫자가 +,-,*,/ 보다 작은 값을 리턴해야 한다.
					string buf = data.at(data.size() - 1);
					data.pop_back();
					cout << buf;
				}
				data.push_back(a);
			}
		}
	}
	while (data.size() != 0) {
		string buf;
		buf = data.at(data.size() - 1);
		data.pop_back();
		cout << buf;
	}
	return 0;
}