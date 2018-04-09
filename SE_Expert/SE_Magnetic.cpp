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
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
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