#include <iostream>
#include <cmath>
#include <string>
#include <vector>
using namespace std;

class Points {
public:
	int xpos;
	int ypos;
};
int distance(int h1, int h2, int m1, int m2, vector<Points> pt);
int main(void)
{
	string inputs;
	cin >> inputs;
	int h1, h2, m1, m2;

	Points p1,p2,p3,p4,p5,p6,p7,p8,p9,p0;
	p1.xpos = 0;	p1.ypos = 0;
	p2.xpos = 0;	p2.ypos = 1;
	p3.xpos = 0;	p3.ypos = 2;
	p4.xpos = 1;	p4.ypos = 0;
	p5.xpos = 1;	p5.ypos = 1;
	p6.xpos = 1;	p6.ypos = 2;
	p7.xpos = 2;	p7.ypos = 0;
	p8.xpos = 2;	p8.ypos = 1;
	p9.xpos = 2;	p9.ypos = 2;
	p0.xpos = 3;	p0.ypos = 1;
	
	vector<Points> pt;
	pt.push_back(p0);	pt.push_back(p1);	pt.push_back(p2);pt.push_back(p3);pt.push_back(p4);pt.push_back(p5);	pt.push_back(p6);pt.push_back(p7);pt.push_back(p8);pt.push_back(p9);

	h1 = inputs.at(0) - '0';
	h2 = inputs.at(1) - '0';
	m1 = inputs.at(3) - '0';
	m2 = inputs.at(4) - '0';
	
	int answer = distance(h1, h2, m1, m2, pt);
	int ah1, ah2, am1, am2;
	ah1 = h1;
	ah2 = h2;
	am1 = m1;
	am2 = m2;

	m1 += 6;
	m2 += 0;
	if (m1 > 10)
		m1 -= 6;
	else
	{
		int dis = distance(h1, h2, m1, m2, pt);
		if (dis < answer)
		{
			answer = dis;
			ah1 = h1;
			ah2 = h2;
			am1 = m1;
			am2 = m2;
		}
		m1 -= 6;
	}

	for (int i = 0; i < 25; i++)
	{
		h1 += 2;
		h2 += 4;
		if (h2 >= 10)
		{
			h2 -= 10;
			h1 += 1;
		}
		if (h1 >= 10)
			break;
		
		int dis=distance(h1, h2, m1, m2, pt);
		if (dis < answer)
		{
			answer = dis;
			ah1 = h1;
			ah2 = h2;
			am1 = m1;
			am2 = m2;
		}
		m1 += 6;
		m2 += 0;
		if (m1 > 10)
			m1 -= 6;
		else
		{
			int dis = distance(h1, h2, m1, m2, pt);
			if (dis < answer)
			{
				answer = dis;
				ah1 = h1;
				ah2 = h2;
				am1 = m1;
				am2 = m2;
			}
			m1 -= 6;
		}
		
	}
	string str;
	str += (ah1 + '0');
	str += (ah2 + '0');
	str += ':';
	str += (am1 + '0');
	str += (am2 + '0');
	cout << str;
	return 0;
}
int distance(int h1, int h2, int m1, int m2,vector<Points> pt)
{
	return abs(pt.at(h1).xpos - pt.at(h2).xpos) + abs(pt.at(h1).ypos - pt.at(h2).ypos) + abs(pt.at(h2).xpos - pt.at(m1).xpos) + abs(pt.at(h2).ypos - pt.at(m1).ypos) + abs(pt.at(m1).xpos - pt.at(m2).xpos) + abs(pt.at(m1).ypos - pt.at(m2).ypos);
}