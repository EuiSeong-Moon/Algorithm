#include <iostream>
#include <queue>
using namespace std;
int map[21][21];
int shark_size = 2;
int flag[22][22];
class Points {	//아기상어
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
	while (shark.xpos != -1) {	//상어 물고기 하나먹기=BFS한 번 호출이며 +=를 통해 전체 시간 구하기.
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
	
	for (int i = 0; i < 22; i++)	//구간반복을 막기위한 플래그_맵
	{
		for (int j = 0; j < 22; j++)
		{
			if (1 <= i && i <= N && 1 <= j && j <= N)
				flag[i][j] = 0;
			else
				flag[i][j] = -1;
		}
	}
	flag[shark.xpos][shark.ypos] = -1;	//상어위치 반복 불가

	while (!barket.empty()) {	//BFS로 찾음 같은 distance는 배열에 모으고 이 중 가장 위쪽 가장좌측인 것을 선택
		Points pt;
		pt = barket.front();
		barket.pop();
		if (index != 0 && arr[index - 1].distance < pt.distance)	//distance우선순위에서 밀리므로 더 이상 탐색 필요x
			fflag = 1;
		if (fflag == 1)
		{
			pt=sorts(arr, index);	//아기상어가 물고기 먹었을 때 셋팅
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
		if (map[pt.xpos][pt.ypos] < shark_size && map[pt.xpos][pt.ypos] != 0) {		//BFS를 통한 탐색
			arr[index++] = pt;
		}
		if (pt.direct != 2 && flag[pt.xpos-1][pt.ypos]==0 && shark_move(pt.xpos - 1, pt.ypos)) {	//북
			Points new_pt;
			new_pt.xpos = pt.xpos - 1;	new_pt.ypos = pt.ypos;	new_pt.direct = 4;	new_pt.distance = pt.distance + 1;
			barket.push(new_pt);
			flag[pt.xpos - 1][pt.ypos] = -1;
		}
		if (pt.direct != 1 && flag[pt.xpos][pt.ypos - 1]==0 && shark_move(pt.xpos, pt.ypos - 1)) {	//서
			Points new_pt;
			new_pt.xpos = pt.xpos;	new_pt.ypos = pt.ypos - 1;	new_pt.direct = 3;	new_pt.distance = pt.distance + 1;
			barket.push(new_pt);
			flag[pt.xpos][pt.ypos - 1] = -1;
		}
		if (pt.direct != 3 && flag[pt.xpos][pt.ypos + 1]==0 && shark_move(pt.xpos, pt.ypos + 1)) {	//동
			Points new_pt;
			new_pt.xpos = pt.xpos;	new_pt.ypos = pt.ypos + 1;	new_pt.direct = 1; new_pt.distance = pt.distance + 1;
			barket.push(new_pt);
			flag[pt.xpos][pt.ypos + 1] = -1;
		}
		if (pt.direct != 4 && flag[pt.xpos + 1][pt.ypos]==0 && shark_move(pt.xpos + 1, pt.ypos)) {	//남
			Points new_pt;
			new_pt.xpos = pt.xpos + 1;	new_pt.ypos = pt.ypos; new_pt.direct = 2;	new_pt.distance = pt.distance + 1;
			barket.push(new_pt);
			flag[pt.xpos + 1][pt.ypos] = -1;
		}
	}
	if (index != 0 && fflag == 0)
	{	//먹이 발견 distance가 최대 distance인 경우 반복 끝내고 물고기 먹기 위한 분기문.
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
Points sorts(Points arr[40],int size) {	//같은 거리상 물고기 우선순위 할당
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
	if (map[xpos][ypos] <= shark_size)	//아기 상어가 자기보다 큰 물고기 제외 물고기 지나가기 위한 함수.
		return true;
	return false;
}