#include <iostream>
#include <utility>
#include <stack>
#include <vector>
using namespace std;
int n;
double E, W, S, N;
stack <double*> percent;
//4개 다 0일 올라가면 0이아니어야 되는데, 0인거같음 왜냐면 나누기니까 이부분에 대한 해결이 필요함.
void MoveE(double& e, double& w, double& s, double& n)
{
	double* dum = new double[4];
	dum[0] = e;
	dum[1] = w;
	dum[2] = s;
	dum[3] = n;
	percent.push(dum);
	e *= E;	w = 0;	s *= E;	n *= E;
}
void MoveW(double& e, double& w, double& s, double& n)
{
	double* dum = new double[4];
	dum[0] = e;
	dum[1] = w;
	dum[2] = s;
	dum[3] = n;
	percent.push(dum);
	e = 0;	w *= W;	s *= W;	n *= W;
}
void MoveS(double& e, double& w, double& s, double& n)
{
	double* dum = new double[4];
	dum[0] = e;
	dum[1] = w;
	dum[2] = s;
	dum[3] = n;
	percent.push(dum);
	e *= S;	w *= S;	s *= S;	n = 0;
}
void MoveN(double& e, double& w, double& s, double& n)
{
	double* dum = new double[4];
	dum[0] = e;
	dum[1] = w;
	dum[2] = s;
	dum[3] = n;
	percent.push(dum);
	e *= N;	w *= N;	s = 0;	n *= N;
}

int main(void)
{
	vector <char> flag;
	vector<pair<int, int>> flagpoint;
	cin >> n >> E >> W >> S >> N;
	n--;
	E /= 100;	W /= 100;	S /= 100;	N /= 100;
	int lenght = n, mid = 1;
	vector <pair<int, int>> barket;
	stack <char> load;
	double pointE = E, pointW = W, pointS = S, pointN = N;
	double answer = 0;
	//n이 1이상
	int x = 0, y = 0;
	while (n != 0)
	{//맨 마지막 안끝남 왜냐면 우선 하나의 포인트에서 E,W 즉 2개이상 못가게 막을때가 안되고있음 flag를 따로 빼서 다시 설계해야 할꺼같음
		int ll = 0;
		pair<int, int> node(x, y);
		for (int i = 0; i < flagpoint.size(); i++)
		{
			if (flagpoint.at(i).first==x && flagpoint.at(i).second==y)
				ll = i;
		}
		if (ll != 0)
		{
			if (pointE != 0 && flag.at(ll) != 'E')
			{
				load.push('E');
				MoveE(pointE, pointW, pointS, pointN);
				barket.push_back(node);
				x += 1;
				n--;
			}
			else if (pointW != 0 && flag.at(ll) != 'W')
			{
				load.push('W');
				MoveW(pointE, pointW, pointS, pointN);
				barket.push_back(node);
				x -= 1;
				n--;
			}
			else if (pointN != 0 && flag.at(ll) != 'N')
			{
				load.push('N');
				MoveN(pointE, pointW, pointS, pointN);
				barket.push_back(node);
				y += 1;
				n--;
			}
			else if (pointS != 0 && flag.at(ll) != 'S')
			{
				load.push('S');
				MoveS(pointE, pointW, pointS, pointN);
				barket.push_back(node);
				y -= 1;
				n--;
			}
			else if (n == lenght)
				break;
			else
				mid = 0;
		}
		else
		{
			if (pointE != 0)
			{
				load.push('E');
				MoveE(pointE, pointW, pointS, pointN);
				barket.push_back(node);
				x += 1;
				n--;
			}
			else if (pointW != 0 )
			{
				load.push('W');
				MoveW(pointE, pointW, pointS, pointN);
				barket.push_back(node);
				x -= 1;
				n--;
			}
			else if (pointN != 0)
			{
				load.push('N');
				MoveN(pointE, pointW, pointS, pointN);
				barket.push_back(node);
				y += 1;
				n--;
			}
			else if (pointS != 0)
			{
				load.push('S');
				MoveS(pointE, pointW, pointS, pointN);
				barket.push_back(node);
				y -= 1;
				n--;
			}
			else if (n == lenght)
				break;
			else
				mid = 0;
		}
		if (n == 0 || mid == 0)
		{
			mid = 1;
			answer += pointE;	answer += pointW;	answer += pointS;	answer += pointN;
			n++;
			switch (load.top())
			{
			case 'E':
				pointE = percent.top()[0];	flag.push_back('E');	flagpoint.push_back(node);
				//	if (pointW != 0)	pointW /= W;
				pointW = percent.top()[1];
				//	if (pointN != 0)	pointN /= N;
				pointN = percent.top()[3];
				//	if (pointS != 0)	pointS /= S;
				pointS = percent.top()[2];
				load.pop();	barket.pop_back();	percent.pop();
				break;
			case 'W':
				pointW = percent.top()[1];	flag.push_back('W');	flagpoint.push_back(node);
				//if (pointE != 0)	pointE /= E;
				pointE = percent.top()[0];
				//if (pointN != 0)	pointN /= N;
				pointN = percent.top()[3];
				//if (pointS != 0)	pointS /= S;
				pointS = percent.top()[2];
				load.pop();	barket.pop_back();	percent.pop();
				break;
			case 'S':
				pointS = percent.top()[2];	flag.push_back('S');	flagpoint.push_back(node);
				//if (pointW != 0)	pointW /= W;
				pointW = percent.top()[1];
				//if (pointN != 0)	pointN /= N;
				pointN = percent.top()[3];
				//if (pointE != 0)	pointE /= E;
				pointE = percent.top()[0];
				load.pop();	barket.pop_back();	percent.pop();
				break;
			case 'N':
				pointN = percent.top()[3];	flag.push_back('N');	flagpoint.push_back(node);
				//if (pointW != 0)	pointW /= W;
				pointW = percent.top()[1];
				//if (pointE != 0)	pointE /= E;
				pointE = percent.top()[0];
				//if (pointS != 0)	pointS /= S;
				pointS = percent.top()[2];
				load.pop();	barket.pop_back();	percent.pop();
				break;
			}
		}
	}
	cout << answer;
}