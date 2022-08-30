#include<iostream>
#include<vector>
#include<string>
#include<cmath>
using namespace std;

int main(void)
{
	int N, K;
	cin >> N >> K;
	string str;
	cin >> str;
	vector<long long> barket;
	int flag = 0;
	int dpot = 0;
	vector<int> num;
	for (int i = 0; i < str.size(); i++) {
		if (str.at(i) == '-')
			flag = 1;
		else if(isdigit(str.at(i))){
			dpot += 1;
			num.push_back(str.at(i) - '0');
		}
		if (str.at(i) == ',' || i == str.size() - 1)
		{
			long long pp = 0;
			for (int l = 0; l < num.size(); l++) {
				long long bb = num.at(l);
				bb *= pow(10, num.size() - (l + 1));
				pp += bb;
			}
			num.clear();
			if (flag == 0) {	//양수
				pp = pp;
			}
			else {	//음수
				pp = pp*-1;
			}
			barket.push_back(pp);
			flag = 0;
			dpot = 0;
			continue;
		}
	}
	for (int i = 0; i < K; i++) {
		for (int k = 0; k < barket.size()-1; k++) {
			barket.at(k) = barket.at(k + 1) - barket.at(k);
		}
		barket.pop_back();
	}
	for (int i = 0; i < barket.size(); i++) {
		if (i == barket.size() - 1)
			cout << barket.at(i);
		else
			cout << barket.at(i) << ',';
	}
	return 0;
}