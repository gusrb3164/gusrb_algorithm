#include<iostream>
#include<list>
using namespace std;
list<char> lt;
list<char>::iterator iter;
void _plus()
{
	char c;
	cin >> c;
	lt.insert(iter, c);
}
void _left()
{
	if (iter != lt.begin())
		iter--;
}
void _right()
{
	if (iter != lt.end())
		iter++;
}
void _erase()
{
	if (iter != lt.begin())
		iter = lt.erase(--iter);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	string s;
	cin >> s;
	cin >> n;
	
	for (int i = 0; i < s.size(); i++)
		lt.push_back(s[i]);
	iter = lt.end();
	for (int i = 0; i < n; i++)
	{
		char c;
		cin >> c;
		if (c == 'P')
			_plus();
		else if (c == 'L')
			_left();
		else if (c == 'D')
			_right();
		else if (c == 'B')
			_erase();
	}
	for (iter = lt.begin(); iter != lt.end(); iter++)
	{
		cout << *iter;
	}
	cout << endl;
}