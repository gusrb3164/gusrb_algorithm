#include<iostream>
#include<queue>
#include<cstring>
char normal[100][100];
char _normal[100][100];
bool isPassed[100][100];
using namespace std;
int N;
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

int testNormal()
{

	int count = 0;
	queue<pair<int, int>>q;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (!isPassed[i][j]) //지나간 구역이아니면 검사 실시
			{
				q.push(make_pair(i, j));
				char c = normal[i][j];
				while (!q.empty())
				{
					int y = q.front().first;
					int x = q.front().second;
					q.pop();
					for (int k = 0; k < 4; k++)
					{
						int ny = dy[k] + y;
						int nx = dx[k] + x;
						if (!isPassed[ny][nx] && ny >= 0 && nx >= 0 && ny < N && nx < N && normal[ny][nx] == c)
						{
							q.push(make_pair(ny, nx));
							isPassed[ny][nx] = true;
						}
					}
				}
				count++;
			}
		}
	}
	return count;
}
int _testNormal()
{

	int count = 0;
	queue<pair<int, int>>q;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (!isPassed[i][j]) //지나간 구역이아니면 검사 실시
			{
				q.push(make_pair(i, j));
				char c = _normal[i][j];
				while (!q.empty())
				{
					int y = q.front().first;
					int x = q.front().second;
					q.pop();
					for (int k = 0; k < 4; k++)
					{
						int ny = dy[k] + y;
						int nx = dx[k] + x;
						if (!isPassed[ny][nx] && ny >= 0 && nx >= 0 && ny < N && nx < N && _normal[ny][nx] == c)
						{
							q.push(make_pair(ny, nx));
							isPassed[ny][nx] = true;
						}
					}
				}
				count++;
			}
		}
	}
	return count;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> normal[i];
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (normal[i][j] == 'G')
				_normal[i][j] = 'R';
			else
				_normal[i][j] = normal[i][j];
		}
	}
	cout << testNormal() << " ";
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			isPassed[i][j] = false;
	}
	cout << _testNormal() << endl;
}