#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
int t_case, start, result;
bool isVisited[10000];

string BFS()
{
	queue<pair<int, string>> q;
	q.push(make_pair(start, ""));
	isVisited[start] = true;
	while (!q.empty())
	{
		int x = q.front().first;
		string s = q.front().second;
		q.pop();
		if (x == result)
			return s;
		int nx;
		//D
		nx = (x * 2) % 10000;
		if (!isVisited[nx])
		{
			q.push(make_pair(nx, s + "D"));
			isVisited[nx] = true;
		}
		//S
		nx = x > 0 ? x - 1 : 9999;
		if (!isVisited[nx])
		{
			q.push(make_pair(nx, s + "S"));
			isVisited[nx] = true;
		}
		//L
		nx = (x % 1000) * 10 + x / 1000;
		if (!isVisited[nx])
		{
			q.push(make_pair(nx, s + "L"));
			isVisited[nx] = true;
		}
		//R
		nx = (x / 10) + (x % 10) * 1000;
		if (!isVisited[nx])
		{
			q.push(make_pair(nx, s + "R"));
			isVisited[nx] = true;
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> t_case;
	for (int i = 0; i < t_case; i++)
	{
		memset(isVisited, false, sizeof(isVisited));
		cin >> start >> result;
		cout << BFS() << endl;
	}
}