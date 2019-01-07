#include <iostream>
#include <vector>

using namespace std;
int food[11][11];
int plus_food[11][11];
int flag[12][12];
class Wood_info {
public:
	int xpos;
	int ypos;
	vector<int> woods;
};
int main(void)
{
	for (int i = 0; i < 12; i++)
	{
		for (int j = 0; j < 12; j++)
		{
			
			flag[i][j] = -1;
		}
	}
	int N, M, K,buf,buf2,buf3;
	cin >> N >> M >> K;
	vector<Wood_info> wood;
	for (int i = 1; i < N+1; i++) {
		for (int j = 1; j < N+1; j++) {
			cin >> buf;
			plus_food[i][j] = buf;
			food[i][j] = 5;
			flag[i][j] = 0;
		}
	}
	for (int i = 0; i < M; i++)
	{
		cin >> buf >> buf2>>buf3;
		Wood_info w;
		w.xpos = buf;	w.ypos = buf2;	w.woods.push_back(buf3);
		wood.push_back(w);
		flag[buf][buf2] = 1;
	}

	for (int i = 0; i < K; i++)
	{
		//봄+여름
		int size = wood.size();
		for (int j = 0; j < size; j++)
		{
			//int flag = 0;
			for (int k = wood.at(j).woods.size() - 1; k >= 0; k--) {
				food[wood.at(j).xpos][wood.at(j).ypos] -= wood.at(j).woods.at(k);
				if (food[wood.at(j).xpos][wood.at(j).ypos] < 0)
				{
					food[wood.at(j).xpos][wood.at(j).ypos] += wood.at(j).woods.at(k);
					int kk = k;
					while (kk >= 0)
					{
						food[wood.at(j).xpos][wood.at(j).ypos] += wood.at(j).woods.at(kk) / 2;
						kk--;
					}
					wood.at(j).woods.erase(wood.at(j).woods.begin(), wood.at(j).woods.begin() + k + 1);
					//if (wood.at(j).woods.size() == 0)
						//flag[wood.at(j).xpos][wood.at(j).ypos] = 0;
					break;
				}
				else {
					wood.at(j).woods.at(k) += 1;
				}
			}
		}
		//가을
		size = wood.size();
		for(int j=0;j<size;j++){
			for (int k = wood.at(j).woods.size() - 1; k >= 0; k--){
				if (wood.at(j).woods.at(k) % 5 == 0) {
					if (flag[wood.at(j).xpos - 1][wood.at(j).ypos]==1) {
						for (int m = 0; m < wood.size(); m++)
						{
							if(wood.at(m).xpos== wood.at(j).xpos - 1 && wood.at(m).ypos== wood.at(j).ypos)
								wood.at(m).woods.push_back(1);
						}
					}
					else if(flag[wood.at(j).xpos - 1][wood.at(j).ypos] !=- 1) {
						Wood_info w;
						w.xpos = wood.at(j).xpos - 1;	w.ypos = wood.at(j).ypos;	w.woods.push_back(1);
						wood.push_back(w);
						flag[wood.at(j).xpos - 1][wood.at(j).ypos] = 1;
					}
					if (flag[wood.at(j).xpos + 1][wood.at(j).ypos]==1)
					{
						for (int m = 0; m < wood.size(); m++) {
							if ((wood.at(m).xpos == wood.at(j).xpos + 1 && wood.at(m).ypos == wood.at(j).ypos))
							wood.at(m).woods.push_back(1);
						}
					}
					else if(flag[wood.at(j).xpos + 1][wood.at(j).ypos]!=-1){
						Wood_info w;
						w.xpos = wood.at(j).xpos + 1;	w.ypos = wood.at(j).ypos;	w.woods.push_back(1);
						wood.push_back(w);
						flag[wood.at(j).xpos + 1][wood.at(j).ypos] = 1;
					}
					if (flag[wood.at(j).xpos][wood.at(j).ypos-1]==1) {
						for (int m = 0; m < wood.size(); m++) {
							if((wood.at(m).xpos == wood.at(j).xpos && wood.at(m).ypos == wood.at(j).ypos - 1 ))
							wood.at(m).woods.push_back(1);
						}
					}
					else if(flag[wood.at(j).xpos][wood.at(j).ypos - 1] != -1) {
						Wood_info w;
						w.xpos = wood.at(j).xpos;	w.ypos = wood.at(j).ypos-1;	w.woods.push_back(1);
						wood.push_back(w);
						flag[wood.at(j).xpos][wood.at(j).ypos - 1] = 1;
					}
					if(flag[wood.at(j).xpos][wood.at(j).ypos + 1]==1) {
						for (int m = 0; m < wood.size(); m++)
						{
							if ((wood.at(m).xpos == wood.at(j).xpos && wood.at(m).ypos == wood.at(j).ypos + 1 ))
							wood.at(m).woods.push_back(1);
						}
					}
					else if(flag[wood.at(j).xpos][wood.at(j).ypos + 1]!=-1){
						Wood_info w;
						w.xpos = wood.at(j).xpos;	w.ypos = wood.at(j).ypos+1;	w.woods.push_back(1);
						wood.push_back(w);
						flag[wood.at(j).xpos][wood.at(j).ypos + 1] = 1;
					}
					if (flag[wood.at(j).xpos+1][wood.at(j).ypos + 1]==1) {
						for (int m = 0; m < wood.size(); m++)
						{
							if ((wood.at(m).xpos == wood.at(j).xpos + 1 && wood.at(m).ypos == wood.at(j).ypos + 1))
							wood.at(m).woods.push_back(1);
						}
					}
					else if(flag[wood.at(j).xpos + 1][wood.at(j).ypos + 1]!=-1){
						Wood_info w;
						w.xpos = wood.at(j).xpos+1;	w.ypos = wood.at(j).ypos + 1;	w.woods.push_back(1);
						wood.push_back(w);
						flag[wood.at(j).xpos + 1][wood.at(j).ypos + 1] = 1;
					}
					if (flag[wood.at(j).xpos-1][wood.at(j).ypos + 1]==1) {
						for (int m = 0; m < wood.size(); m++)
						{
							if ((wood.at(m).xpos == wood.at(j).xpos - 1 && wood.at(m).ypos == wood.at(j).ypos + 1 ))
							wood.at(m).woods.push_back(1);
						}
					}
					else if(flag[wood.at(j).xpos - 1][wood.at(j).ypos + 1]!=-1){
						Wood_info w;
						w.xpos = wood.at(j).xpos-1;	w.ypos = wood.at(j).ypos + 1;	w.woods.push_back(1);
						wood.push_back(w);
						flag[wood.at(j).xpos - 1][wood.at(j).ypos + 1] = 1;
					}
					if (flag[wood.at(j).xpos+1][wood.at(j).ypos - 1]==1) {
						for (int m = 0; m < wood.size(); m++)
						{
							if ((wood.at(m).xpos == wood.at(j).xpos + 1 && wood.at(m).ypos == wood.at(j).ypos - 1 ))
							wood.at(m).woods.push_back(1);
						}
					}
					else if(flag[wood.at(j).xpos + 1][wood.at(j).ypos - 1]!=-1){
						Wood_info w;
						w.xpos = wood.at(j).xpos+1;	w.ypos = wood.at(j).ypos - 1;	w.woods.push_back(1);
						wood.push_back(w);
						flag[wood.at(j).xpos + 1][wood.at(j).ypos - 1] = 1;
					}
					if (flag[wood.at(j).xpos-1][wood.at(j).ypos - 1]==1) {
						for (int m = 0; m < wood.size(); m++)
						{
							if ((wood.at(m).xpos == wood.at(j).xpos - 1 && wood.at(m).ypos == wood.at(j).ypos - 1))
								wood.at(m).woods.push_back(1);
						}
					}
					else if(flag[wood.at(j).xpos - 1][wood.at(j).ypos - 1]!=-1){
						Wood_info w;
						w.xpos = wood.at(j).xpos-1;	w.ypos = wood.at(j).ypos - 1;	w.woods.push_back(1);
						wood.push_back(w);
						flag[wood.at(j).xpos - 1][wood.at(j).ypos - 1]=1;
					}
				}
			}
		}
		//겨울
		for (int p = 1; p <= N; p++)
		{
			for (int q = 1; q <= N; q++)
				food[p][q] += plus_food[p][q];
		}
	}
	int answer = 0;
	for (int i = 0; i < wood.size(); i++)
	{
		answer += wood.at(i).woods.size();
	}
	cout << answer << endl;
	return 0;
}