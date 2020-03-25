#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
queue <pair<int, int>>q;
int arr[1000][1000];
int checkDay[1000][1000];
int day = 0;
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };
int M, N;

void _test(int nx, int ny, int x, int y)
{
	if (arr[nx][ny] == 0)
	{
		arr[nx][ny] = 1;
		q.push({ nx,ny });
		checkDay[nx][ny] = checkDay[x][y] + 1;
	}
}
int main()
{
	cin >> M >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] == 1)
			{
				q.push({ i, j });
				checkDay[i][j] = 0;
			}
		}
	}

	int size = q.size();
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && ny >= 0 && nx < N && ny < M)
				_test(nx, ny, x, y);
		}
	}
	int result = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			result = max(result, checkDay[i][j]);
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (arr[i][j] == 0)
				result = -1;
		}
	}
	cout << result;
}