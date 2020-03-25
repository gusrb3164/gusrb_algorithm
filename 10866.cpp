#include<iostream>
#include<deque>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	deque<int>dq;
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int d;
		string s;
		cin >> s;
		if (s == "push_back" || s == "push_front")
			cin >> d;
		if (s == "push_front")
			dq.push_front(d);
		else if (s == "push_back")
			dq.push_back(d);
		else if(s == "pop_front")
		{
			if (dq.empty())
				cout << -1 << endl;
			else
			{
				int num = dq.front();
				dq.pop_front();
				cout << num << endl;
			}
		}
		else if (s == "pop_back")
		{
			if (dq.empty())
				cout << -1 << endl;
			else
			{
				int num = dq.back();
				dq.pop_back();
				cout << num << endl;
			}
		}
		else if (s == "size")
		{
			cout << dq.size() << endl;
		}
		else if (s == "empty")
		{
			cout << dq.empty() << endl;
		}
		else if (s == "front")
		{
			if (dq.empty())
				cout << -1 << endl;
			else
			{
				cout << dq.front() << endl;
			}
		}
		else if (s == "back")
		{
			if (dq.empty())
				cout << -1 << endl;
			else
			{
				cout << dq.back() << endl;
			}
		}
	}
}