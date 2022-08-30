#include <iostream>
#include <queue>
using namespace std;
int map[21][21];
int shark_size = 2;
int flag[22][22];
class Points {	//�Ʊ���
public:
	int xpos;
	int ypos;
	int distance;
	int direct;
	int eat;
	int flag=0;
};
bool shark_move(int xpos, int ypos);
Points sorts(Points arr[40], int size);
Points BFS(Points shark, int N);
int main(void)
{
	Points shark;
	int N,buf,time=0;
	cin >> N;
	for (int i = 0; i < 21; i++)
	{
		for (int j = 0; j < 21; j++)
		{
			map[i][j] = -1;
		}
	}
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> buf;
			map[i][j] = buf;
			if (buf == 9)
			{
				shark.xpos = i;
				shark.ypos = j;
				shark.distance = 0;
				shark.eat = 0;
				shark.direct = 0;
			}
		}
	}
	shark=BFS(shark,N);
	time += shark.distance;
	while (shark.xpos != -1) {	//��� ����� �ϳ��Ա�=BFS�� �� ȣ���̸� +=�� ���� ��ü �ð� ���ϱ�.
		shark=BFS(shark, N);
		time += shark.distance;
	}
	cout << time << endl;
}
Points BFS(Points shark,int N) {
	queue<Points> barket;
	shark.distance = 0;
	barket.push(shark);
	Points new_shark;
	new_shark.eat = shark.eat;
	new_shark.xpos = -1;
	new_shark.distance = 0;
	Points arr[40];
	int index = 0, fflag = 0;;
	
	for (int i = 0; i < 22; i++)	//�����ݺ��� �������� �÷���_��
	{
		for (int j = 0; j < 22; j++)
		{
			if (1 <= i && i <= N && 1 <= j && j <= N)
				flag[i][j] = 0;
			else
				flag[i][j] = -1;
		}
	}
	flag[shark.xpos][shark.ypos] = -1;	//�����ġ �ݺ� �Ұ�

	while (!barket.empty()) {	//BFS�� ã�� ���� distance�� �迭�� ������ �� �� ���� ���� ���������� ���� ����
		Points pt;
		pt = barket.front();
		barket.pop();
		if (index != 0 && arr[index - 1].distance < pt.distance)	//distance�켱�������� �и��Ƿ� �� �̻� Ž�� �ʿ�x
			fflag = 1;
		if (fflag == 1)
		{
			pt=sorts(arr, index);	//�Ʊ�� ����� �Ծ��� �� ����
			new_shark.xpos = pt.xpos;
			new_shark.ypos = pt.ypos;
			new_shark.eat++;
			new_shark.distance = pt.distance;
			if (new_shark.eat == shark_size)
			{
				new_shark.eat = 0;
				shark_size++;
			}
			map[pt.xpos][pt.ypos] = 0;
			map[shark.xpos][shark.ypos] = 0;
			break;
		}
		if (map[pt.xpos][pt.ypos] < shark_size && map[pt.xpos][pt.ypos] != 0) {		//BFS�� ���� Ž��
			arr[index++] = pt;
		}
		if (pt.direct != 2 && flag[pt.xpos-1][pt.ypos]==0 && shark_move(pt.xpos - 1, pt.ypos)) {	//��
			Points new_pt;
			new_pt.xpos = pt.xpos - 1;	new_pt.ypos = pt.ypos;	new_pt.direct = 4;	new_pt.distance = pt.distance + 1;
			barket.push(new_pt);
			flag[pt.xpos - 1][pt.ypos] = -1;
		}
		if (pt.direct != 1 && flag[pt.xpos][pt.ypos - 1]==0 && shark_move(pt.xpos, pt.ypos - 1)) {	//��
			Points new_pt;
			new_pt.xpos = pt.xpos;	new_pt.ypos = pt.ypos - 1;	new_pt.direct = 3;	new_pt.distance = pt.distance + 1;
			barket.push(new_pt);
			flag[pt.xpos][pt.ypos - 1] = -1;
		}
		if (pt.direct != 3 && flag[pt.xpos][pt.ypos + 1]==0 && shark_move(pt.xpos, pt.ypos + 1)) {	//��
			Points new_pt;
			new_pt.xpos = pt.xpos;	new_pt.ypos = pt.ypos + 1;	new_pt.direct = 1; new_pt.distance = pt.distance + 1;
			barket.push(new_pt);
			flag[pt.xpos][pt.ypos + 1] = -1;
		}
		if (pt.direct != 4 && flag[pt.xpos + 1][pt.ypos]==0 && shark_move(pt.xpos + 1, pt.ypos)) {	//��
			Points new_pt;
			new_pt.xpos = pt.xpos + 1;	new_pt.ypos = pt.ypos; new_pt.direct = 2;	new_pt.distance = pt.distance + 1;
			barket.push(new_pt);
			flag[pt.xpos + 1][pt.ypos] = -1;
		}
	}
	if (index != 0 && fflag == 0)
	{	//���� �߰� distance�� �ִ� distance�� ��� �ݺ� ������ ����� �Ա� ���� �б⹮.
		Points pt;
		pt = sorts(arr, index);
		new_shark.xpos = pt.xpos;
		new_shark.ypos = pt.ypos;
		new_shark.eat++;
		new_shark.distance = pt.distance;
		if (new_shark.eat == shark_size)
		{
			new_shark.eat = 0;
			shark_size++;
		}
		map[pt.xpos][pt.ypos] = 0;
		map[shark.xpos][shark.ypos] = 0;
	}
	return new_shark;		
}
Points sorts(Points arr[40],int size) {	//���� �Ÿ��� ����� �켱���� �Ҵ�
	for (int i = 0; i < size; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (arr[i].xpos > arr[j].xpos)
			{
				arr[i].flag = -1;
			}
			else if (arr[i].xpos == arr[j].xpos && arr[i].ypos > arr[j].ypos)
			{
				arr[i].flag = -1;
			}
		}
	}
	for (int i = 0; i < size; i++)
	{
		if (arr[i].flag != -1)
			return arr[i];
	}
}
bool shark_move(int xpos, int ypos)
{
	if (map[xpos][ypos] <= shark_size)	//�Ʊ� �� �ڱ⺸�� ū ����� ���� ����� �������� ���� �Լ�.
		return true;
	return false;
}