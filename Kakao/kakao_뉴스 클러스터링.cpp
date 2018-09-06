#include <string>
#include <vector>
#include <iostream>
#include <cctype>
#include <cmath>
#include <algorithm>
// string문자열 비교는 str.at()을통한 일일이 비교를 해야 한다.
using namespace std;
int solution(string str1, string str2);
int main(void)
{
	string str1="rrrr12";
	string str2="rr1+rr2";
	int answer;
	answer=solution(str1, str2);
	cout << answer;
}
int solution(string str1, string str2) {
	double answer = 0;
	vector<string> str_set1;
	vector<string> str_set2;
	// 문자 조합 함수 A,B만들기
	for (int i = 0; i<str1.size() - 1; i++)
	{
		string new_str;
		if (isalpha(str1.at(i)) == 0 || isalpha(str1.at(i + 1)) == 0)
			continue;
		str1.at(i) = toupper(str1.at(i));
		str1.at(i + 1) = toupper(str1.at(i + 1));
		new_str += str1.at(i);	new_str += str1.at(i + 1);
		
		str_set1.push_back(new_str);
	}
	for (int i = 0; i<str2.size() - 1; i++)
	{
		string new_str;
		if (isalpha(str2.at(i)) == 0 || isalpha(str2.at(i + 1)) == 0)
			continue;
		str2.at(i) = toupper(str2.at(i));
		str2.at(i + 1) = toupper(str2.at(i + 1));
		new_str += str2.at(i);	new_str += str2.at(i + 1);
		
		str_set2.push_back(new_str);
	}
	// 공집합 예외처리
	if (str_set1.size() == 0 && str_set2.size() == 0)
		answer = 1;
	// A,B 함수 교집합을 만들고 합집합은 전체-교집합
	else {
		int *flag = new int[str_set2.size()];
		for (int i = 0; i < str_set2.size(); i++)
			flag[i] = 0;
		for (int i = 0; i<str_set1.size(); i++)
		{
			for (int j = 0; j<str_set2.size(); j++)
			{
				if (flag[j]==0 && str_set1.at(i).at(0) == str_set2.at(j).at(0) && str_set1.at(i).at(1) == str_set2.at(j).at(1))	//find가 아닌 flag 이용이 좋음.
				{
					flag[j] = 1;
					answer++;
					break;
				}
			}
			
		}
		answer /= (str_set1.size() + str_set2.size() - answer);
	}
	answer *= 65536;
	int real_answer = (int)floor(answer);
	return real_answer;
}