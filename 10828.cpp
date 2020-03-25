#include<iostream>
#include<string.h>

using namespace std;

int stack[10001];

void push(int* i, int stack[], int push_num);
void pop(int* i, int stack[]);
void top(int* i, int stack[]);
void size(int* i);
void empty(int* i);
int main()
{
	string com;
	int index = -1;
	int num;
	cin >> num;
	for (int i = 0; i < num; i++)
	{
		cin >> com;
		if (com == "push")
		{
			int push_num;
			cin >> push_num;
			push(&index, stack, push_num);
		}
		else if (com == "pop")
			pop(&index, stack);
		else if (com == "top")
			top(&index, stack);
		else if (com == "size")
			size(&index);
		else if (com == "empty")
			empty(&index);
		
	}
}
void push(int* i, int stack[], int push_num)
{
	(*i)++;
	stack[*i] = push_num;
}
void pop(int* i, int stack[])
{
	if (*i == -1)
	{
		cout << -1 << endl;
		return;
	}
	cout << stack[*i] << endl;
	(*i)--;
}
void top(int* i, int stack[])
{
	if (*i == -1)
	{
		cout << -1 << endl;
		return;
	}
	cout << stack[*i] << endl;
}
void size(int* i)
{
	cout << *i + 1 << endl;
}
void empty(int* i)
{
	if (*i == -1)
		cout << 1 << endl;
	else
		cout << 0 << endl;
}