#include<iostream>
#include <string>
using namespace std;

char U[3][3];
char D[3][3];
char F[3][3];
char B[3][3];
char L[3][3];
char R[3][3];


int main(void) {
	int T;
	cin >> T;
	for (int test = 0; test < T; test++) {
		for (int p = 0; p < 3; p++) {
			for (int q = 0; q < 3; q++) {
				U[p][q] = 'w';
				D[p][q] = 'y';
				F[p][q] = 'r';
				B[p][q] = 'o';
				L[p][q] = 'g';
				R[p][q] = 'b';
			}
		}
		// ȸ���� ���� �� ȸ��
		// �ڱ��ڽŵ� ȸ����.
		// ȸ���� �� ȸ������ ���ֺ��°Ͱ��ݴ� �� F�� �ð����� B�� �ð������ ���� �ݴ��̴�(B�� �ݽð�� F�� �ð�����̶� ����).
		// ���� ������ �� �ӽ� ���� �ݵ�� ����ؾ� ��. �ƴϸ� �ٲ�� ���߿� �� �ٲ�.
		// �� ���� 3���� ��ȭ�ϴµ� �� �� ������ ��Ȯ�� ���ؼ� �ٲ���� ù��° ��� �� �ٲٰ� �� �� ° ��� �� �ٲٰ� ���� ° ��� �ٹٲٰ� �ƴϸ� ���۾Ⱦ���ó�� ������

		int N;
		string buf;
		cin >> N;
		for (int k = 0; k < N; k++) {
			cin >> buf;
			char buf1, buf2, buf3, buf4;
			if (buf.at(0) == 'L')	//����
			{
				if (buf.at(1) == '-') {	//�ݽð�
					for (int i = 0; i < 3; i++) {
						buf1 = U[i][0];	//U[0][0]�� ��������  F,D,B�� ������ U[1][0], U[2][0]������ ����
						buf2 = F[i][0];
						buf3 = D[2 - i][2];
						buf4 = B[i][0];
						B[i][0] = buf1;
						U[i][0]=buf2;
						F[i][0] = buf3;
						D[2-i][2]=buf4;

					}
					char new_L[3][3];		//(L �ڱ��ڽ� �����°�)
					for (int d = 0; d < 3; d++) {
						for (int f = 0; f < 3; f++) {
							new_L[d][f] = L[d][f];
						}
					}
					for (int d = 0; d < 3; d++) {
						L[0][d] = new_L[d][2];
						L[d][2] = new_L[2][2 - d];
						L[2][2 - d] = new_L[2 - d][0];
						L[2 - d][0] = new_L[0][d];
					}
				}
				else
				{	//L �ð���� ������
					for (int i = 0; i < 3; i++) {
						buf1 = B[i][0];
						buf2 = U[i][0];
						buf3 = F[i][0];
						buf4 = D[2-i][2];
						U[i][0] = buf1;
						F[i][0] = buf2;
						D[2-i][2] = buf3;
						B[i][0] = buf4;
					}
					char new_L[3][3];
					for (int d = 0; d < 3; d++) {
						for (int f = 0; f < 3; f++) {
							new_L[d][f] = L[d][f];
						}
					}
					for (int d = 0; d < 3; d++) {
						L[d][2]= new_L[0][d];
						L[2][2 - d]=new_L[d][2];
						L[2 - d][0]=new_L[2][2 - d];
						L[0][d]=new_L[2 - d][0];
					}
				}
			}
			else if (buf.at(0) == 'R') {
				if (buf.at(1) == '-') {
					for (int i = 0; i < 3; i++) {
						buf1 = B[i][2];
						buf2 = U[i][2];
						buf3 = F[i][2];
						buf4 = D[2-i][0];
						U[i][2] = buf1;
						F[i][2]=buf2;
						D[2-i][0]=buf3;
						B[i][2]=buf4;
					}
					char new_L[3][3];
					for (int d = 0; d < 3; d++) {
						for (int f = 0; f < 3; f++) {
							new_L[d][f] = R[d][f];
						}
					}
					for (int d = 0; d < 3; d++) {
						R[0][d] = new_L[d][2];
						R[d][2] = new_L[2][2 - d];
						R[2][2 - d] = new_L[2 - d][0];
						R[2 - d][0] = new_L[0][d];
					}
				}
				else
				{
					for (int i = 0; i < 3; i++) {
						buf1 = U[i][2];
						buf2 = F[i][2];
						buf3 = D[2-i][0];
						buf4 = B[i][2];
						B[i][2] = buf1;
						U[i][2] = buf2;
						F[i][2] = buf3;
						D[2 - i][0] = buf4;
					}
					char new_L[3][3];
					for (int d = 0; d < 3; d++) {
						for (int f = 0; f < 3; f++) {
							new_L[d][f] =R[d][f];
						}
					}
					for (int d = 0; d < 3; d++) {
						R[d][2] = new_L[0][d];
						R[2][2 - d] = new_L[d][2];
						R[2 - d][0] = new_L[2][2 - d];
						R[0][d] = new_L[2 - d][0];
					}
				}
			}
			else if (buf.at(0) == 'F') {
				if (buf.at(1) == '-') {
					for (int i = 0; i < 3; i++) {
						buf1 = R[2][i];
						buf2 = D[2][i];
						buf3 = L[2][i];
						buf4=U[2][i];
						U[2][i] = buf1;
						R[2][i]=buf2 ;
						D[2][i]=buf3 ;
						L[2][i] = buf4;
					}
					char new_L[3][3];
					for (int d = 0; d < 3; d++) {
						for (int f = 0; f < 3; f++) {
							new_L[d][f] = F[d][f];
						}
					}
					for (int d = 0; d < 3; d++) {
						F[0][d] = new_L[d][2];
						F[d][2] = new_L[2][2 - d];
						F[2][2 - d] = new_L[2 - d][0];
						F[2 - d][0] = new_L[0][d];
					}
				}
				else
				{
					for (int i = 0; i < 3; i++) {
						buf1 = U[2][i];	buf2 = R[2][i];	buf3 = D[2][i];	buf4 = L[2][i];
						R[2][i] = buf1;
						D[2][i] = buf2;
						L[2][i] = buf3;
						U[2][i] = buf4;
					}
					char new_L[3][3];
					for (int d = 0; d < 3; d++) {
						for (int f = 0; f < 3; f++) {
							new_L[d][f] = F[d][f];
						}
					}
					for (int d = 0; d < 3; d++) {
						F[d][2] = new_L[0][d];
						F[2][2 - d] = new_L[d][2];
						F[2 - d][0] = new_L[2][2 - d];
						F[0][d] = new_L[2 - d][0];
					}
				}
			}
			else if (buf.at(0) == 'B') {
				if (buf.at(1) == '-') {
					for (int i = 0; i < 3; i++)
					{
						buf1 = L[0][i];	buf2 = D[0][i];	buf3 = R[0][i];	buf4 = U[0][i];
						U[0][i]=buf1;
						L[0][i]=buf2;
						D[0][i]=buf3 ;
						R[0][i]=buf4;
					}
					char new_L[3][3];
					for (int d = 0; d < 3; d++) {
						for (int f = 0; f < 3; f++) {
							new_L[d][f] = B[d][f];
						}
					}
					for (int d = 0; d < 3; d++) {
						B[0][d] = new_L[d][2];
						B[d][2] = new_L[2][2 - d];
						B[2][2 - d] = new_L[2 - d][0];
						B[2 - d][0] = new_L[0][d];
					}
				}
				else
				{
					for (int i = 0; i < 3; i++)
					{
						buf1 = U[0][i];	buf2 = L[0][i];	buf3 = D[0][i];	buf4 = R[0][i];
						L[0][i] = buf1;
						D[0][i] = buf2;
						R[0][i] =buf3;
						U[0][i] = buf4;
					}
					char new_L[3][3];
					for (int d = 0; d < 3; d++) {
						for (int f = 0; f < 3; f++) {
							new_L[d][f] = B[d][f];
						}
					}
					for (int d = 0; d < 3; d++) {
						B[d][2] = new_L[0][d];
						B[2][2 - d] = new_L[d][2];
						B[2 - d][0] = new_L[2][2 - d];
						B[0][d] = new_L[2 - d][0];
					}
				}
			}
			else if (buf.at(0) == 'U') {
				if (buf.at(1) == '-') {
					for (int i = 0; i < 3; i++) {
						buf1 = B[2][i];	buf2 = L[2-i][2];	buf3 = F[0][2-i];	buf4 = R[i][0];
						L[2 - i][2] = buf1;
						F[0][2-i] = buf2;
						R[i][0] = buf3;
						B[2][i] = buf4;
					}
					char new_L[3][3];
					for (int d = 0; d < 3; d++) {
						for (int f = 0; f < 3; f++) {
							new_L[d][f] = U[d][f];
						}
					}
					for (int d = 0; d < 3; d++) {
						U[0][d] = new_L[d][2];
						U[d][2] = new_L[2][2 - d];
						U[2][2 - d] = new_L[2 - d][0];
						U[2 - d][0] = new_L[0][d];
					}
				}
				else
				{
					for (int i = 0; i < 3; i++) {
						buf1 = L[i][2];	buf2 = F[0][i];	buf3 = R[2 - i][0];	buf4 = B[2][2-i];
						B[2][2-i]=buf1;
						L[i][2]=buf2;
						F[0][i]=buf3;
						R[2-i][0]=buf4;
					}
					char new_L[3][3];
					for (int d = 0; d < 3; d++) {
						for (int f = 0; f < 3; f++) {
							new_L[d][f] = U[d][f];
						}
					}
					for (int d = 0; d < 3; d++) {
						U[d][2] = new_L[0][d];
						U[2][2 - d] = new_L[d][2];
						U[2 - d][0] = new_L[2][2 - d];
						U[0][d] = new_L[2 - d][0];
					}
				}
			}
			else if (buf.at(0) == 'D') {
				if (buf.at(1) == '-') {
					for (int i = 0; i < 3; i++) {
						buf1 = L[i][0];	buf2 = F[2][i];	buf3 = R[2 - i][2];	buf4 = B[0][2-i];
							B[0][2-i]= buf1;
							L[i][0]=buf2 ;
							F[2][i] = buf3;
							R[2-i][2]=buf4 ;
					}
					char new_L[3][3];
					for (int d = 0; d < 3; d++) {
						for (int f = 0; f < 3; f++) {
							new_L[d][f] = D[d][f];
						}
					}
					for (int d = 0; d < 3; d++) {
						D[0][d] = new_L[d][2];
						D[d][2] = new_L[2][2 - d];
						D[2][2 - d] = new_L[2 - d][0];
						D[2 - d][0] = new_L[0][d];
					}
				}
				else
				{
					for (int i = 0; i < 3; i++) {
						buf1 = B[0][i];	buf2 = L[2-i][0];	buf3 = F[2][2-i];	buf4 = R[i][2];
						L[2-i][0] = buf1;
						F[2][2-i] = buf2;
						R[i][2] = buf3;
						B[0][i] = buf4;
					}
					char new_L[3][3];
					for (int d = 0; d < 3; d++) {
						for (int f = 0; f < 3; f++) {
							new_L[d][f] = D[d][f];
						}
					}
					for (int d = 0; d < 3; d++) {
						D[d][2] = new_L[0][d];
						D[2][2 - d] = new_L[d][2];
						D[2 - d][0] = new_L[2][2 - d];
						D[0][d] = new_L[2 - d][0];
					}
				}
			}
		}
		for (int p = 0; p < 3; p++) {
			for (int q = 0; q < 3; q++) {
				cout << U[p][q];
			}
			cout << endl;
		}
	}
	return 0;
}