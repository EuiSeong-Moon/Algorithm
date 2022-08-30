#include<iostream>
#include<string>

using namespace std;
//동적 배열을 이용한 stack 제작
int* push(int* stacks,int a,int& size)
{
	int* newstacks = new int[size + 1];
	for (int i = 0; i < size; i++)
		newstacks[i] = stacks[i];
	newstacks[size] = a;
	delete stacks;
	size += 1;
	return newstacks;
}
int* pop(int* stacks, int& size)
{
	if (size == 0) {
		cout << "-1" << endl;
		return stacks;
	}
	else
	{
		int* newstacks = new int[size - 1];
		for (int i = 0; i < size - 1; i++)
			newstacks[i] = stacks[i];
		cout << stacks[size - 1] << endl;
		delete stacks;
		size -= 1;
		return newstacks;
	}
}
void sizess(int& size)
{
	cout << size << endl;
}
void empty(int& size)
{
	if (size == 0)
		cout << "1" << endl;
	else
		cout << "0" << endl;
}
void top(int* stacks, int& size)
{
	if (size == 0)
		cout << "-1" << endl;
	else
		cout << stacks[size - 1] << endl;
}
int main(void)
{
	int* stacks = new int[0];
	int size = 0;
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		string command;
		cin >> command;
		if (command == "push")
		{
			int a;
			cin >> a;
			stacks = push(stacks, a, size);
		}
		else if (command == "pop")
		{
			stacks = pop(stacks, size);
		}
		else if (command == "size")
		{
			sizess(size);
		}
		else if (command == "empty")
		{
			empty(size);
		}
		else if (command == "top")
		{
			top(stacks, size);
		}
	}
}