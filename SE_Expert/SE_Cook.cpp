#include <iostream>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <algorithm>
using namespace std;

class Points {
public:
	int xpos;
	int ypos;
	int value;
};
int combination(int n, int r, int* data, int* flag, int N, vector<vector<int>>& m_data_ba, vector<int>& m_data);
int Find_minimum(int** s_table, int N, vector<vector<int>> m_data_ba);
int main(void)
{
	int T;
	cin >> T;
	for (int t = 1; t < T+1; t++)
	{
		int N,data;
		cin >> N;
		int **table = new int*[N];
		for (int i = 0; i < N; i++)
			table[i] = new int[N];
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cin >> data;
				table[i][j] = data;
			}
		}
		int **s_table = new int*[N];
		for (int i = 0; i < N; i++)
			s_table[i] = new int[N];
		for (int i = 0; i < N; i++)
		{
			for (int j = i+1; j < N; j++)
				s_table[i][j] = table[i][j] + table[j][i];
		}
		int* datas = new int[N];
		int* flag = new int[N];
		for (int i = 0; i < N; i++)
		{
			flag[i] = 0;
			datas[i] = i;
		}
		vector<int> m_data;
		vector<vector<int>> m_data_ba;
		combination(N, N / 2, datas, flag,N,m_data_ba,m_data);
		int answer = Find_minimum(s_table, N, m_data_ba);
		cout << "#" << t << " " << answer << endl;
	}
}
//combination dynamic arrya

int combination(int n, int r, int* data,int* flag,int N,vector<vector<int>>& m_data_ba,vector<int>& m_data)
{
	if (n == r) {
		int i;
		for (i = 0; i<n; i++) {
			flag[i] = 1;
		}
		for (i = 0; i<N; i++) {
			if (flag[i] == 1) m_data.push_back(data[i]);
		}
		for (i = 0; i<n; i++) {
			flag[i] = 0;
		}
		m_data_ba.push_back(m_data);
		m_data.clear();
		return 0;
	}
	if (r == 1) {
		int i, j;
		for (i = 0; i<n; i++) {
			flag[i] = 1;
			for (j = 0; j<N; j++) {
				if (flag[j] == 1)
					m_data.push_back(data[j]);
			}
			flag[i] = 0;
			m_data_ba.push_back(m_data);
			m_data.clear();
		}
		return 0;
	}
	flag[n - 1] = 1;
	combination(n - 1, r - 1,data,flag,N,m_data_ba,m_data);
	flag[n - 1] = 0;
	combination(n - 1, r,data,flag,N,m_data_ba,m_data);
}

int Find_minimum(int** s_table,int N,vector<vector<int>> m_data_ba)
{
	int values = 0, values2 = 0,minium=30000;
	vector<int> reverse;
	for (int i = 0; i < m_data_ba.size()-1; i++)
	{
		for (int j = 0; j < m_data_ba.at(i).size(); j++)
		{
			for (int k = j + 1; k < m_data_ba.at(i).size(); k++)
				values += s_table[m_data_ba.at(i).at(j)][m_data_ba.at(i).at(k)];
		}
		for (int j = 0; j < N; j++)
		{
			if (find(m_data_ba.at(i).begin(), m_data_ba.at(i).end(), j) != m_data_ba.at(i).end())
				continue;
			reverse.push_back(j);
		}
		for (int j = 0; j < reverse.size(); j++)
		{
			for (int k = j + 1; k < reverse.size(); k++)
				values2 += s_table[reverse.at(j)][reverse.at(k)];
		}
		if (minium > abs(values - values2))
			minium = abs(values - values2);
		values = 0;
		values2 = 0;
		reverse.clear();
	}
	return minium;
}
