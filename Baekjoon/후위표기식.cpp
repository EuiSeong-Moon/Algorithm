#include<iostream>
#include<vector>
#include<string>
using namespace std;
//���� �߿��� ����Ʈ
// 1. )�ΰ�� ( ���� ���
// 2. �켱������ �� ���ų� �������� stack�� �̹��ִ°�� pop�ؼ� ��� �� ������ push
// 3. �� ���� ��� �׳� push�ϰ� �� �������� ������ pop
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
				while (data.size() != 0 && isOperators(data.at(data.size() - 1)) >= orders) {	//�ݵ�� (,),���ڰ� +,-,*,/ ���� ���� ���� �����ؾ� �Ѵ�.
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