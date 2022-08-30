#include<iostream>
#include<vector>
#include<queue>
using namespace std;
bool flag[1001] = { false, };
bool node_flag[100000] = { false, };
vector<vector<int>> links;
vector<vector<int>> Nodes;
queue<pair<int, int>> barket;
int main(void) {		//간선 정보 저장이 핵심 터널과 노드 벡터를 따로만들어야 메모리초과가 안난다.
	int N, K, M,buf;
	cin >> N >> K >> M;
	for (int i = 0; i < N; i++) {
		vector<int> buf;
		Nodes.push_back(buf);
	}
	for (int i = 0; i < M; i++) {
		vector<int> bufs;
		for (int j = 0; j < K; j++) {
			cin >> buf;
			bufs.push_back(buf-1);
			Nodes.at(buf - 1).push_back(i);
		}
		links.push_back(bufs);
	}
	
	//flag[0] = true;
	pair<int, int> s_p;	s_p.first = 0;	s_p.second = 1;
	node_flag[0] = true;
	barket.push(s_p);
	int answer = 100000;
	while (barket.size() != 0) {
		pair<int,int> pos;	pos = barket.front();	barket.pop();
		if (pos.second > answer)
			continue;
		if (pos.first == N - 1)
		{
			cout <<pos.second << endl;
			return 0;
		}
		for (int m = 0; m < Nodes.at(pos.first).size(); m++) 
		{
			if (flag[Nodes.at(pos.first).at(m)])
				continue;
			flag[Nodes.at(pos.first).at(m)] =true;
			for (int n = 0; n < links.at(Nodes.at(pos.first).at(m)).size(); n++) {
				if (node_flag[links.at(Nodes.at(pos.first).at(m)).at(n)])
					continue;
				node_flag[links.at(Nodes.at(pos.first).at(m)).at(n)] = true;
				pair<int, int> new_pos;	new_pos.first = links.at(Nodes.at(pos.first).at(m)).at(n);	new_pos.second = pos.second + 1;
				barket.push(new_pos);
			}
		}
		
	}
	cout << "-1" << endl;	//놓치지좀말자 이런것좀 제발
	return 0;
}