#include<iostream>
#include<stack>
#include<queue>
#include<cstring>
using namespace std;
/*bool **line = new bool*[nodenumber + 1];		//�������� �Ҵ��ϸ�, stack overflow�� ���� ��ü�� �Ұ��� �մϴ�.
for (int i = 0; i < nodenumber + 1; i++)
{
	line[i] = new bool[nodenumber + 1];
	memset(line[i], false, sizeof(bool) * nodenumber + 1);
}
bool **line2 = new bool*[nodenumber + 1];
for (int i = 0; i < nodenumber + 1; i++)
{
	line2[i] = new bool[nodenumber + 1];
	memset(line2[i], false, sizeof(bool) * nodenumber + 1);
}*/
bool line[1001][1001];
bool line2[1001][1001];
int main(void)
{
	unsigned short nodenumber = 0;
	unsigned short linenumber = 0;
	unsigned short startnumber;
	cin >> nodenumber >> linenumber >> startnumber;
	

	for (int i = 0; i < linenumber; i++)	//line ǥ��
	{
		unsigned short a, b;
		cin >> a >> b;
		line[a][b] = true;
		line[b][a] = true;
		line2[a][b] = true;
		line2[b][a] = true;
	}

	//DFS
	stack<unsigned short> dumy;
	unsigned short* answer=new unsigned short[nodenumber];
	bool *node=new bool[nodenumber+1];
	for (int i = 1; i < nodenumber + 1; i++)	//������ ��� ���� üũ���� �����ϱ� ���ؼ�
		node[i] = true;
	dumy.push(startnumber);
	answer[nodenumber - 1] = 0;
	answer[0]=startnumber;
	char ll = 1;
	int current = startnumber;
	for (int i = 1; i < nodenumber + 1; i++)
	{
				dumy.push(i);
				if (node[i] == true)
				{
					answer[ll++]=i;
					node[i] = false;
				}
				line[current][i] = false;
				line[i][current] = false;
				current = i;
				if (answer[nodenumber-1] != 0)
					break;
				i = 0;

		if (i == nodenumber)	//�������̶� ���ϰ� �� ���
		{
			i = dumy.top();
			dumy.pop();
			current = dumy.top();
		}
	}

	for (int i = 0; i < nodenumber; i++)
			cout << answer[i] << endl;

	//BFS
	queue<unsigned short> dumy2;
	answer[nodenumber - 1] = 0;
//	bool *node = new bool[nodenumber + 1];
	for (int i = 1; i < nodenumber + 1; i++)	//������ ��� ���� üũ���� �����ϱ� ���ؼ�
		node[i] = true;
	answer[0]=startnumber;
	ll = 1;
	dumy2.push(startnumber);
	unsigned short current2;
	char j = 1;
	while (dumy2.size() != 0)	//ť
	{
		current2 = dumy2.front();
		dumy2.pop();
		for (int i = 1; i < nodenumber + 1; i++)
		{
			if (line2[current2][i] == true)	//����Ǿ� ������
			{
				dumy2.push(i);
				if (node[i] == true)	//����迭���� ������� �ߺ� ���� ���ؼ�
				{
					answer[ll++];
					node[i] = false;
				}
				line2[current2][i] = false;
				line2[i][current2] = false;
				if (answer[nodenumber-1]!= 0)
				{
					j = 0;
					break;
				}
			}
		}
		if (j == 0)
			break;
	}
	for (int i = 0; i < nodenumber; i++)
			cout << answer[i] <<endl;
	return 0;
}