/////////////////////////////////////////////////////////////////////////////////////////////
// 기본 제공코드는 임의 수정해도 관계 없습니다. 단, 입출력 포맷 주의
// 아래 표준 입출력 예제 필요시 참고하세요.
// 표준 입력 예제
// int a;
// float b, c;
// double d, e, f;
// char g;
// char var[256];
// long long AB;
// cin >> a;                            // int 변수 1개 입력받는 예제
// cin >> b >> c;                       // float 변수 2개 입력받는 예제 
// cin >> d >> e >> f;                  // double 변수 3개 입력받는 예제
// cin >> g;                            // char 변수 1개 입력받는 예제
// cin >> var;                          // 문자열 1개 입력받는 예제
// cin >> AB;                           // long long 변수 1개 입력받는 예제
/////////////////////////////////////////////////////////////////////////////////////////////
// 표준 출력 예제
// int a = 0;                            
// float b = 1.0, c = 2.0;               
// double d = 3.0, e = 0.0; f = 1.0;
// char g = 'b';
// char var[256] = "ABCDEFG";
// long long AB = 12345678901234567L;
// cout << a;                           // int 변수 1개 출력하는 예제
// cout << b << " " << c;               // float 변수 2개 출력하는 예제
// cout << d << " " << e << " " << f;   // double 변수 3개 출력하는 예제
// cout << g;                           // char 변수 1개 출력하는 예제
// cout << var;                         // 문자열 1개 출력하는 예제
// cout << AB;                          // long long 변수 1개 출력하는 예제
/////////////////////////////////////////////////////////////////////////////////////////////

#include<iostream>
#include<stack>
#include<vector>
using namespace std;
int DFS(int* operators,stack<int>& barket, int N,stack<stack<int>>& answer);
int main(int argc, char** argv)
{
	int test_case;
	int T;
	/*
	아래의 freopen 함수는 input.txt 를 read only 형식으로 연 후,
	앞으로 표준 입력(키보드) 대신 input.txt 파일로부터 읽어오겠다는 의미의 코드입니다.
	//여러분이 작성한 코드를 테스트 할 때, 편의를 위해서 input.txt에 입력을 저장한 후,
	freopen 함수를 이용하면 이후 cin 을 수행할 때 표준 입력 대신 파일로부터 입력을 받아올 수 있습니다.
	따라서 테스트를 수행할 때에는 아래 주석을 지우고 이 함수를 사용하셔도 좋습니다.
	freopen 함수를 사용하기 위해서는 #include <cstdio>, 혹은 #include <stdio.h> 가 필요합니다.
	단, 채점을 위해 코드를 제출하실 때에는 반드시 freopen 함수를 지우거나 주석 처리 하셔야 합니다.
	*/
	//freopen("input.txt", "r", stdin);
	cin >> T;
	/*
	여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
	*/
	for (test_case = 1; test_case <= T; ++test_case)
	{

		/////////////////////////////////////////////////////////////////////////////////////////////
		/*
		이 부분에 여러분의 알고리즘 구현이 들어갑니다.
		*/
		/////////////////////////////////////////////////////////////////////////////////////////////
		int N, min = 100000000, max = -100000000;
		stack<int> barket;
		stack<stack<int>> answer;
		cin >> N;
		int operators[4];
		int* operate = new int[N];
		int* flag = new int[N];
		int* bu_oper = new int[N];
		vector<int> oper;
	
		for (int i = 0; i < 4; i++)
		{
			int buffer;
			cin >> buffer;
			operators[i] = buffer;
		}
		for (int i = 0; i < N; i++)
		{
			flag[i] = 0;
			int buffer;
			cin >> buffer;
			operate[i] = buffer;
		}
		DFS(operators, barket, N, answer);
		int sizes = answer.size();
		for (int i = 0; i < sizes; i++)
		{
			stack<int> kk;
			kk = answer.top();
			answer.pop();
			int j = 1;
			int ssz = kk.size();
			while (j < ssz + 1)
			{
				oper.push_back(kk.top());
				kk.pop();
				j++;
			}
			
			bu_oper[0] = operate[0];
			for (int k = 0; k < N - 1; k++)
			{
				if (oper.at(oper.size()-1) == 0)
					bu_oper[k + 1] = bu_oper[k] + operate[k + 1];
				else if (oper.at(oper.size() - 1) == 1)
					bu_oper[k + 1] = bu_oper[k] - operate[k + 1];
				else if (oper.at(oper.size() - 1) == 2)
					bu_oper[k + 1] = bu_oper[k] * operate[k + 1];
				else if (oper.at(oper.size() - 1) == 3)
					bu_oper[k + 1] = bu_oper[k] / operate[k + 1];
				else
					cout << "error";
				oper.pop_back();
			}
			if (bu_oper[N - 1] > max)
				max = bu_oper[N - 1];
			if (bu_oper[N - 1] < min)
				min = bu_oper[N - 1];
		}
	
		cout <<"#"<<test_case<<" "<< max - min << endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
int DFS(int* operators,stack<int>& barket,int N,stack<stack<int>>& answer)
{
	int ban;
	int ban_flag[4] = { 0, };
//	barket.push(operators[0]);
	for (int i = 0; i < N - barket.size(); i++)
	{
		if (operators[0] != 0 && ban_flag[0] == 0)
		{
			operators[0]--;
			barket.push(0);
			ban = DFS(operators, barket, N,answer);
		}
		else if (operators[1] != 0 && ban_flag[1] == 0)
		{
			operators[1]--;
			barket.push(1);
			ban = DFS(operators, barket, N,answer);
		}
		else if (operators[2] != 0 && ban_flag[2] == 0)
		{
			operators[2]--;
			barket.push(2);
			ban = DFS(operators, barket, N,answer);
		}
		else if (operators[3] != 0 && ban_flag[3] == 0)
		{
			operators[3]--;
			barket.push(3);
			ban = DFS(operators, barket, N,answer);
		}
		else
		{
			if (barket.size() == 0)
				continue;
			if (barket.size() == N - 1)
				answer.push(barket);
			ban = barket.top();
			barket.pop();
			operators[ban]++;
			return ban;
		}
		ban_flag[ban] = -1;
	}
	return ban;
}