#include <iostream>
#include <cmath>
using namespace std;
long long map[1000001];
long long *tree;
long long* lazy;
//index�� Ʈ�� ��Ʈ���� �»� ���������� 1,2,3,4,������ �迭 �ε��� �����ϴ� ��.
long long make_tree(int index, int start, int end)
{
	//int node = (start + end) / 2;
	if (start == end)
	{
		lazy[index] = 0;
		return tree[index] = map[start];
	}
	else
	{
		lazy[index] = 0;
		return tree[index] = make_tree(index * 2, start, (start + end) / 2) + make_tree(index * 2+1, (start + end) / 2 + 1, end);
	}
	//return tree[index];
}
void update_lazy(int start, int end, int index) {
	if (lazy[index] != 0)
	{
		tree[index] += (end - start + 1)*lazy[index];
		if (start != end) {
			lazy[index * 2] += lazy[index];
			lazy[index * 2 + 1] += lazy[index];
		}
		lazy[index] = 0;
	}
}
void update(long long d, int index, int start, int end, int update_index_s,int update_index_e) {
		//update �ϳ��� �ϱ� update �ε����� �ؽ� �� �ε��� (a~b)�����̹Ƿ� a~b���� �ݺ��� �̿��ϸ� nlogN�� �Ǳ� ������ �ð��ʰ�.
	update_lazy(start, end, index);
	if (update_index_e<start || update_index_s>end)
		return;
	if (update_index_s <= start && end <= update_index_e) {
		tree[index] += (end - start + 1)*d;
		if (start != end) {
			lazy[index * 2] += d;
			lazy[index * 2 + 1] += d;
		}
		return;
	}
	update(d, index * 2 , start, (start + end) / 2, update_index_s,update_index_e);
	update(d, index * 2+1, (start + end) / 2 + 1, end,update_index_s,update_index_e);
	tree[index] = tree[index * 2] + tree[index * 2 + 1];


}
long long sums(int start, int end, int s_start, int s_end,int index) {
	update_lazy(start, end, index);
	if (s_start > end || s_end < start)
		return 0;//������ ������� �ƴϸ� �����.
	if (start >= s_start && end <= s_end)	//���� �����ȿ� �Լ��� ������ ��� ������ ����
		return tree[index];
	
	else
	{
		return sums(start, (start+end)/2, s_start, s_end, index * 2)+sums((start+end)/2+1,end,s_start,s_end,index*2+1);
		
	}
}
int main(void)
{
	cin.tie(0);
	int N, M, K,flag,a,b;
	long long buf,c;

	cin >> N >> M >> K;
	//int* m_map = new int[N];
	for (int i = 0; i < N; i++)
	{
		cin >> buf;
		map[i] = buf;
	}
	tree = new long long[(int)pow(2, ceil(log2(N)) + 2)];
	lazy = new long long[(int)pow(2, ceil(log2(N)) + 2)];
	make_tree(1, 0, N-1);
	for (int i = 0; i < M + K; i++) {
		cin >> flag;
		if(flag == 1)
		{
			cin >> a >> b >> c;	
			update(c, 1, 0, N - 1, a - 1, b - 1);
		}
		else if (flag == 2) {
			cin >> a >> b;
			long long sum = 0;
			cout << sums(0, N - 1, a-1, b-1, 1)<<"\n";
		}
	}
	return 0;
}