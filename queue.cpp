#include <iostream>
#include <vector>
#include <string>

using namespace std;
void choice(string a, vector<int>& b,vector<int>& c);

int main(void)
{
	int count;
	vector <int> arr;
	string question;
	vector <int> answer;
	
	cin >> count;

	for (int i = 0; i < count; i++)
	{
		cin >> question;
		choice(question,arr,answer);
	}
	for (int i = 0; i < answer.size()-1; i++)
		cout << answer.at(i) << endl;
	cout << answer.at(answer.size()-1);
	return 0;
}
void pushs(vector<int>& b)
{
	int num;
	cin >> num;
	b.push_back(num);
}
int pops(vector<int>& b)
{
	if (b.size() == 0)
		return -1;
	int num = b.front();
	vector <int> compare;
	for (int i = 0; i < b.size()-1; i++)
	{
		compare.push_back(b.back());
		b.pop_back();
	}
	b.clear();
	for (int i = 0; i < compare.size(); i++)
	{
		b.push_back(compare.back());
		compare.pop_back();
	}

	return num;
}
int sizes(vector<int>& b)
{
	return b.size();
}
int emptys(vector<int>& b)
{
	if (b.size() == 0)
		return 1;
	else
		return 0;
}
int fronts(vector<int>& b)
{
	if (b.size() == 0)
		return -1;
	return b.front();
}
int backs(vector<int>& b)
{
	if (b.size() == 0)
		return -1;
	return b.back();
}
void choice(string a, vector<int>& b, vector<int>& c)
{
	if (a == "push" || a=="PUSH")
		pushs(b);
	else if (a == "pop" || a=="POP")
		 c.push_back(pops(b));
	else if (a == "size"|| a=="SIZE")
		c.push_back(sizes(b));
	else if (a == "empty"|| a=="EMPTY")
		c.push_back(emptys(b));
	else if (a == "front"||a=="FRONT")
		c.push_back(fronts(b));
	else if (a == "back"||a=="BACK")
		c.push_back(backs(b));
}