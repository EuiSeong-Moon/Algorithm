/////////////////////////////////////////////////////////////////////////////////////////////
// �⺻ �����ڵ�� ���� �����ص� ���� �����ϴ�. ��, ����� ���� ����
// �Ʒ� ǥ�� ����� ���� �ʿ�� �����ϼ���.
// ǥ�� �Է� ����
// int a;
// float b, c;
// double d, e, f;
// char g;
// char var[256];
// long long AB;
// cin >> a;                            // int ���� 1�� �Է¹޴� ����
// cin >> b >> c;                       // float ���� 2�� �Է¹޴� ���� 
// cin >> d >> e >> f;                  // double ���� 3�� �Է¹޴� ����
// cin >> g;                            // char ���� 1�� �Է¹޴� ����
// cin >> var;                          // ���ڿ� 1�� �Է¹޴� ����
// cin >> AB;                           // long long ���� 1�� �Է¹޴� ����
/////////////////////////////////////////////////////////////////////////////////////////////
// ǥ�� ��� ����
// int a = 0;                            
// float b = 1.0, c = 2.0;               
// double d = 3.0, e = 0.0; f = 1.0;
// char g = 'b';
// char var[256] = "ABCDEFG";
// long long AB = 12345678901234567L;
// cout << a;                           // int ���� 1�� ����ϴ� ����
// cout << b << " " << c;               // float ���� 2�� ����ϴ� ����
// cout << d << " " << e << " " << f;   // double ���� 3�� ����ϴ� ����
// cout << g;                           // char ���� 1�� ����ϴ� ����
// cout << var;                         // ���ڿ� 1�� ����ϴ� ����
// cout << AB;                          // long long ���� 1�� ����ϴ� ����
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
	�Ʒ��� freopen �Լ��� input.txt �� read only �������� �� ��,
	������ ǥ�� �Է�(Ű����) ��� input.txt ���Ϸκ��� �о���ڴٴ� �ǹ��� �ڵ��Դϴ�.
	//�������� �ۼ��� �ڵ带 �׽�Ʈ �� ��, ���Ǹ� ���ؼ� input.txt�� �Է��� ������ ��,
	freopen �Լ��� �̿��ϸ� ���� cin �� ������ �� ǥ�� �Է� ��� ���Ϸκ��� �Է��� �޾ƿ� �� �ֽ��ϴ�.
	���� �׽�Ʈ�� ������ ������ �Ʒ� �ּ��� ����� �� �Լ��� ����ϼŵ� �����ϴ�.
	freopen �Լ��� ����ϱ� ���ؼ��� #include <cstdio>, Ȥ�� #include <stdio.h> �� �ʿ��մϴ�.
	��, ä���� ���� �ڵ带 �����Ͻ� ������ �ݵ�� freopen �Լ��� ����ų� �ּ� ó�� �ϼž� �մϴ�.
	*/
	//freopen("input.txt", "r", stdin);
	cin >> T;
	/*
	���� ���� �׽�Ʈ ���̽��� �־����Ƿ�, ������ ó���մϴ�.
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
		�� �κп� �������� �˰��� ������ ���ϴ�.
		*/
		/////////////////////////////////////////////////////////////////////////////////////////////


	}
	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}