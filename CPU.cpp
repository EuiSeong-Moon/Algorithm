#include<iostream>
#include<string>
#include<vector>

using namespace std;
string tobinary_3(int a) {
	vector<char> bufs;
	string out_put;
	int count = 3;
	while (a != 0) {
		if (a % 2 == 0) {
			bufs.push_back('0');
		}
		else {
			bufs.push_back('1');
		}
		a /= 2;
	}
	for (int i = bufs.size()-1; i >=0; i--) {
		out_put += bufs.at(i);
	}
	count -= bufs.size();
	while (count != 0) {
		count -= 1;
		out_put.insert(out_put.begin(), '0');
	}
	return out_put;
}
string tobinary_4(int a) {
	vector<char> bufs;
	string out_put;
	int count = 4;
	while (a != 0) {
		if (a % 2 == 0) {
			bufs.push_back('0');
		}
		else {
			bufs.push_back('1');
		}
		a /= 2;
	}
	for (int i = bufs.size()-1; i >=0; i--) {
		out_put += bufs.at(i);
	}
	count -= bufs.size();
	while (count != 0) {
		count -= 1;
		out_put.insert(out_put.begin(), '0');
	}
	return out_put;
}
int main(void) {
	int N;
	string answer;
	bool flag;
	string str;
	vector<vector<string>> commands;
	cin >> N;
	for (int i = 0; i < N; i++) {
		vector<string> buf;
		for (int j = 0; j < 4; j++) {
			cin >> str;
			buf.push_back(str);
		}
		commands.push_back(buf);
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 4; j++) {
			string command = commands.at(i).at(j);
			string data;
			switch (j) {
			case 0:
				if (command == "ADD" || command=="ADDC") {
					answer = "0000";
					if (command == "ADD") {
						answer += '0';
						flag = true;
					}
					else
					{
						answer += '1';
						flag = false;
					}
				}
				else if (command == "SUB" || command == "SUBC")
				{
					answer = "0001";
					if (command == "SUB") {
						answer += '0';
						flag = true;
					}
					else
					{
						answer += '1';
						flag = false;
					}
				}
				else if (command == "MOV" || command == "MOVC") {
					answer = "0010";
					if (command == "MOV") {
						answer += '0';
						flag = true;
					}
					else
					{
						answer += '1';
						flag = false;
					}
				}
				else if (command == "AND" || command == "ANDC") {
					answer = "0011";
					if (command == "AND") {
						answer += '0';
						flag = true;
					}
					else
					{
						answer += '1';
						flag = false;
					}
				}
				else if (command == "OR" || command == "ORC") {
					answer = "0100";
					if (command == "OR") {
						answer += '0';
						flag = true;
					}
					else
					{
						answer += '1';
						flag = false;
					}
				}
				else if (command == "NOT") {
					answer = "01010";
					flag = true;
				}
				else if (command == "MULT" || command == "MULTC") {
					answer = "0110";
					if (command == "MULT") {
						answer += '0';
						flag = true;
					}
					else
					{
						answer += '1';
						flag = false;
					}
				}
				else if (command == "LSFTL" || command == "LSFTLC") {
					answer = "0111";
					if (command == "LSFTL") {
						answer += '0';
						flag = true;
					}
					else
					{
						answer += '1';
						flag = false;
					}
				}
				else if (command == "LSFTR" || command == "LSFTRC") {
					answer = "1000";
					if (command == "LSFTR") {
						answer += '0';
						flag = true;
					}
					else
					{
						answer += '1';
						flag = false;
					}
				}
				else if (command == "ASFTR" || command == "ASFTRC") {
					answer = "1001";
					if (command == "ASFTR") {
						answer += '0';
						flag = true;
					}
					else
					{
						answer += '1';
						flag = false;
					}
				}
				else if (command == "RL" || command == "RLC") {
					answer = "1010";
					if (command == "RL") {
						answer += '0';
						flag = true;
					}
					else
					{
						answer += '1';
						flag = false;
					}
				}
				else if (command == "RR" || command == "RRC") {
					answer = "1011";
					if (command == "RR") {
						answer += '0';
						flag = true;
					}
					else
					{
						answer += '1';
						flag = false;
					}
				}
				answer += '0';
				break;
			case 1:
				data = tobinary_3(stoi(command));
				answer += data;
				break;
			case 2:
				data = tobinary_3(stoi(command));
				answer += data;
				break;
			case 3:
				if (flag) {
					data = tobinary_3(stoi(command));
					answer += data;
					answer += '0';
				}
				else {
					data = tobinary_4(stoi(command));
					answer += data;
				}
				break;
			}
		}
		cout << answer << endl;
	}
	return 0;
}