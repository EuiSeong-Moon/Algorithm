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

using namespace std;
void magnet2(int** magnet, int magnet_direct, int& answer, int l_flag, int r_flag);
void magnet1(int** magnet, int magnet_direct, int& answer, int r_flag);
void magnet3(int** magnet, int magnet_direct, int& answer, int l_flag, int r_flag);
void magnet4(int** magnet, int magnet_direct, int& answer, int l_flag);
void rights_mv(int** &a, int index);
void left_mv(int** &a, int index);
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
		int k,magnet_num,magnet_direct,answer=0;
		cin >> k;
		int** magnet = new int*[8];
		for (int i = 0; i < 8; i++)
			magnet[i] = new int[8];
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				int buffer;
				cin >> buffer;
				magnet[i][j] = buffer;
			}
		}
		for (int i = 0; i < k; i++)
		{
			cin >> magnet_num;
			magnet_num -= 1;
			cin >> magnet_direct;
			//0 2 6
			switch(magnet_num)
			{
			case 0:
				magnet1(magnet, magnet_direct, answer, 0);
				break;
			case 1:
				magnet2(magnet, magnet_direct, answer, 0,0);
				break;
			case 2:
				magnet3(magnet, magnet_direct, answer, 0,0);
				break;
			case 3:
				magnet4(magnet, magnet_direct, answer, 0);
				break;
			}
		}
		answer = magnet[0][0] + magnet[1][0] * 2 + magnet[2][0] * 4 + magnet[3][0] * 8;
		cout << "#" << test_case << " " << answer << endl;
	}
	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}
void magnet1(int** magnet,int magnet_direct, int& answer,int r_flag)
{
//	int* buff;
//	strcpy(buff, magnet[0]);
	int buf = magnet[0][7];
	int buf2 = magnet[0][0];
	if (magnet_direct == 1)
	{
		if (magnet[0][2] != magnet[1][6] && r_flag == 0)
			magnet2(magnet, 0, answer, 1, 0);
		rights_mv(magnet, 0);
	}
	else
	{
		if (magnet[0][2] != magnet[1][6] && r_flag == 0)
			magnet2(magnet, 1, answer, 1, 0);
		left_mv(magnet, 0);
	}
}
void magnet2(int** magnet, int magnet_direct, int& answer, int l_flag, int r_flag)
{
	int buf = magnet[1][7];
	int buf2 = magnet[1][0];
	if (magnet_direct == 1)
	{
		if (magnet[1][2] != magnet[2][6] && r_flag == 0)
			magnet3(magnet, 0, answer, 1, 0);
		if (magnet[0][2] != magnet[1][6] && l_flag == 0)
			magnet1(magnet, 0, answer, 1);
		rights_mv(magnet, 1);
	
	}
	else
	{
		if (magnet[1][2] != magnet[2][6] && r_flag == 0)
			magnet3(magnet, 1, answer, 1, 0);
		if (magnet[0][2] != magnet[1][6] && l_flag == 0)
			magnet1(magnet, 1, answer, 1);
		left_mv(magnet, 1);
	}
}
void magnet3(int** magnet, int magnet_direct, int& answer, int l_flag, int r_flag)
{
	int buf = magnet[2][7];
	int buf2 = magnet[2][0];
	if (magnet_direct == 1)
	{
		if (magnet[2][2] != magnet[3][6] && r_flag == 0)
			magnet4(magnet, 0, answer, 1);
		if (magnet[1][2] != magnet[2][6] && l_flag == 0)
			magnet2(magnet, 0, answer, 0, 1);
		rights_mv(magnet, 2);
	}
	else
	{
		if (magnet[2][2] != magnet[3][6] && r_flag == 0)
			magnet4(magnet, 1, answer, 1);
		if (magnet[1][2] != magnet[2][6] && l_flag == 0)
			magnet2(magnet, 1, answer, 0, 1);
		left_mv(magnet, 2);
	}
}
void magnet4(int** magnet, int magnet_direct, int& answer, int l_flag)
{
	int buf = magnet[3][7];
	int buf2 = magnet[3][0];
	if (magnet_direct == 1)
	{
		if (magnet[2][2] != magnet[3][6] && l_flag == 0)
			magnet3(magnet, 0, answer, 0, 1);
		rights_mv(magnet, 3);

	}
	else
	{
		if (magnet[2][2] != magnet[3][6] && l_flag == 0)
			magnet3(magnet, 1, answer, 0, 1);
		left_mv(magnet, 3);
	}
}
void rights_mv(int** &a,int index)
{
	int arr[8];
	for (int i = 0; i < 8; i++)
		arr[i] = a[index][i];
	for (int i = 0; i < 8; i++)
	{
		if (i == 7)
			a[index][0] =arr[7];
		else
			a[index][i+1] = arr[i];
	}
}
void left_mv(int** &a, int index)
{
	int arr[8];
	for (int i = 0; i < 8; i++)
		arr[i] = a[index][i];
	for (int i = 0; i < 8; i++)
	{
		if (i == 7)
			a[index][7] = arr[0];
		else
			a[index][i] = arr[i + 1];
	}
}