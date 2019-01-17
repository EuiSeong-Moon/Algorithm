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
#include<queue>
using namespace std;
char map[22][22];
class Commands {
public:
	pair<int, int> pos;
	int direction;
	int memory;
};
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
		int R, C;
		char buf;
		cin >> R >> C;
		for (int i = 0; i < 22; i++)
		{
			for (int j = 0; j < 22; j++)
			{
				map[i][j] = -1;
			}
		}
		for (int i = 1; i <= R; i++) {
			for (int j = 1; j <= C; j++)
			{
				cin >> buf;
				map[i][j] = buf;
			}
		}
		queue<Commands> cm;
		Commands c;	c.pos.first = 1;	c.pos.second = 1;	c.memory = 0;	c.direction = 1;
		cm.push(c);


		int time = 0;
		int flag = 0;
		while (cm.size() != 0)
		{
			time++;
			Commands cc;
			cc = cm.front();
			cm.pop();
			char current = map[cc.pos.first][cc.pos.second];
			vector<Commands> vt;
			if (isdigit(current))
			{
				cc.memory = current-'0';
			}
			else if (current == '<')
				cc.direction = 3;
			else if (current == '>')
				cc.direction = 1;
			else if (current == '^')
				cc.direction = 4;
			else if (current == 'v')
				cc.direction = 2;
			else if (current == '_')
			{
				if (cc.memory == 0)
					cc.direction = 1;
				else
					cc.direction = 3;
			}
			else if (current == '|')
			{
				if (cc.memory == 0)
					cc.direction = 2;
				else
					cc.direction = 4;
			}
			else if (current == '@')
				break;
			else if (current == '+')
			{
				cc.memory++;
				if (cc.memory == 16)
					cc.memory = 0;
			}
			else if (current == '-')
			{
				cc.memory--;
				if (cc.memory == -1)
					cc.memory = 15;
			}
			else if (current == '?') {
				cc.direction = 1;
				for (int i = 2; i <= 4; i++)
				{
					Commands new_pt2;	new_pt2.pos.first = cc.pos.first;	new_pt2.pos.second = cc.pos.second;
					new_pt2.memory = cc.memory;	new_pt2.direction = i;
					vt.push_back(new_pt2);
				}

			}
			vt.push_back(cc);
			for (int k = 0; k < vt.size(); k++)
			{
				switch (vt.at(k).direction) {
				case 1:
					vt.at(k).pos.second += 1;
					if (map[vt.at(k).pos.first][vt.at(k).pos.second] == -1)
						vt.at(k).pos.second = 1;
					cm.push(vt.at(k));
					break;
				case 2:
					vt.at(k).pos.first += 1;
					if (map[vt.at(k).pos.first][vt.at(k).pos.second] == -1)
						vt.at(k).pos.first = 1;
					cm.push(vt.at(k));
					break;
				case 3:
					vt.at(k).pos.second -= 1;
					if (map[vt.at(k).pos.first][vt.at(k).pos.second] == -1)
						vt.at(k).pos.second = C;
					cm.push(vt.at(k));
					break;
				case 4:
					vt.at(k).pos.first -= 1;
					if (map[vt.at(k).pos.first][vt.at(k).pos.second] == -1)
						vt.at(k).pos.first = R;
					cm.push(vt.at(k));
					break;
				}
			}
			if (time == 1600)
			{
				cout << "#"<<test_case<<" NO" << endl;
				flag = 1;
				break;
			}
		}
		if(flag==0)
			cout << "#"<<test_case<<" YES" << endl;
		/////////////////////////////////////////////////////////////////////////////////////////////
		/*
		이 부분에 여러분의 알고리즘 구현이 들어갑니다.
		*/
		/////////////////////////////////////////////////////////////////////////////////////////////


	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}