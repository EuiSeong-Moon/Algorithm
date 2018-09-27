#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

bool solution(vector<string> phone_book) {
	bool answer = true;
	int flag = 0;
	//unordered_set<string> entires;
	unordered_set<string> parts;
	for (int i = 0; i<phone_book.size(); i++)
	{
		string str;
		for (int j = 0; j<phone_book.at(i).size(); j++)
		{
			if (j != phone_book.at(i).size() - 1)
				str += phone_book.at(i).at(j);
			parts.insert(str);
		}
	}
	for (int i = 0; i<phone_book.size(); i++)
	{
		unordered_set<string>::iterator it = parts.find(phone_book.at(i));
		if (it != parts.end())
		{
			answer = false;
			break;
		}
	}
	return answer;
}
