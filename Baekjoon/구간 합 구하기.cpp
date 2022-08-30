#include <iostream>
#include <cmath>
using namespace std;

long long Nodes[1000000];
long long *tree;
long long make_tree(int s,int e,int index) {
	long long data;
	if (s == e) {
		data = Nodes[e];
		tree[index] = data;
	}

	else
		tree[index]=make_tree(s, (s+e) / 2, index * 2) + make_tree((s+e) / 2 + 1, e,  index * 2 + 1);	//index 1부터 시작
	return tree[index];
}

void update(int s, int e, long long value, int point, int index) {

	if (s > point || point > e)
		return;

	tree[index] += value;
	if (s != e)
	{
		update(s, (s+e) / 2,  value, point, index * 2);
		update((s+e) / 2 + 1, e,  value, point, index * 2 + 1);
	}
}
long long sum(int s, int e, int s_s, int s_e, int index) {
	if (s_s > e || s_e < s)
		return 0;
	
	else if (s_s <= s && e <= s_e) {
		return tree[index];
	}
	else{
		return sum(s, (s+e) / 2, s_s, s_e,index * 2)+sum((s+e) / 2 + 1, e, s_s, s_e, index * 2 + 1);
	}
}
int main(void)
{
	cin.tie(0);
	cout.tie(0);
	int N, M, K,flag,buf3,buf4;
	cin >> N >> M >> K;
//	Nodes = new long long[N];
	//long long* tree;
	//cout << (int)pow(2, ceil(log2(N)) + 2) + 1 << endl;
	int size = (int)ceil(log2(N));
	int sz = 1 << (size + 1);
	tree = new long long[sz];

	long long buf,buf2,answer;
	for (int i = 0; i < N; i++)
	{
		cin >> buf;
		Nodes[i]=buf;
	}
	make_tree(0, N - 1,  1);

	for (int i = 0; i < M + K; i++)
	{

		cin >> flag;
		//answer = 0;
		if (flag == 1)
		{
			long long dif;
			cin >> buf3 >> buf2;
			dif = buf2-Nodes[buf3-1];
			Nodes[buf3 - 1] = buf2;
			update(0, N - 1, dif, buf3-1, 1);
		}
		else
		{
			cin >> buf3 >> buf4;
			cout<<sum(0, N - 1, buf3-1, buf4-1,1)<<"\n";
		}
	}
	return 0;
}