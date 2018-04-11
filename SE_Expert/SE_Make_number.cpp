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
#include<stack>
#include<vector>
using namespace std;
int DFS(int* operators,stack<int>& barket, int N,stack<stack<int>>& answer);
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

		/////////////////////////////////////////////////////////////////////////////////////////////
		/*
		�� �κп� �������� �˰��� ������ ���ϴ�.
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
	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
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