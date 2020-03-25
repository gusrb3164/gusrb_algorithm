#include<iostream>
#include<queue>
using namespace std;
int MAP[100][100];
int isPassed[100][100];
int dir[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };
int N, M;

void bfs()
{
	int y = 0, x = 0;
	queue<pair<int, int>>q;
	q.push(pair<int,int>(y, x));
	isPassed[0][0] = 1;

	while (!q.empty())
	{
		y = q.front().first;
		x = q.front().second;
		q.pop();
		if ((y == N - 1) && (x == M - 1))
			break;

		for (int i = 0; i < 4; i++)
		{
			int ny = y + dir[i][0];
			int nx = x + dir[i][1];
			//맵을 벗어나지 않고 이미 지나간 자리도 아니며 지나갈 수 있는 자리인경우
			if ((ny >= 0) && (nx >= 0) && (ny < N) && (nx < M) && (isPassed[ny][nx] == 0) && (MAP[ny][nx] == 1))
			{
				isPassed[ny][nx] = isPassed[y][x] + 1;
				q.push(pair<int, int>(ny, nx));
			}
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		string s;
		cin >> s;
		for (int j = 0; j < M; j++)
			MAP[i][j] = s[j] - '0';
	}
	bfs();
	cout << isPassed[N - 1][M - 1];
	

}