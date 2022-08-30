#include<iostream>
#include<vector>
#include<queue>
using namespace std;
bool flag[1000000] = { false, };
class Node{
public:
	int count;
	int stair;
};
int main(void) {
	int F, S, G, U, D;
	cin >> F >> S >> G >> U >> D;
	queue<Node> data;
	Node n;	n.count = 0;	n.stair = S;
	flag[n.stair] = true;
	data.push(n);
	while (data.size() != 0) {
		Node node;
		node = data.front();
		data.pop();
		if (node.stair == G)
		{
			cout << node.count << endl;
			return 0;
		}
		if (node.stair + U <= F && flag[node.stair+U]==false) {
			flag[node.stair + U] = true;
			Node new_n;	new_n.count = node.count + 1;	new_n.stair = node.stair + U;
			data.push(new_n);
		}
		if (node.stair - D >= 0 && flag[node.stair-D]==false) {
			flag[node.stair - D] = true;
			Node new_n;	new_n.count = node.count + 1;	new_n.stair = node.stair - D;
			data.push(new_n);
		}
	}
	cout << "use the stairs" << endl;
	return 0;
}