#include<iostream>
#include<queue>
using namespace std;
int visited[300][300];
void initialize(int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
			visited[i][j] = 0;
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int mY[8] = { 1,2,1,2,-1,-2,-1,-2 };
	int mX[8] = { -2,-1,2,1,-2,-1,2,1 };
	int tCase;
	cin >> tCase;
	int boardLen, y, x, resultY, resultX;

	for (int i = 0; i < tCase; i++)
	{
		queue<pair<int, int>>q;
		bool flag = true;

		cin >> boardLen;
		initialize(boardLen);  //보드판의 크기를 입력받고 크기만큼 방문횟수배열을 0으로 초기화함
		cin >> y >> x;
		cin >> resultY >> resultX;
		q.push(make_pair(y, x)); //맨 처음 위치를 큐에 넣음
		while (1)
		{
			int ny = q.front().first;
			int nx = q.front().second;
			q.pop();
			if (ny == resultY && nx == resultX)//큐에서 뽑은 위치가 목적지와 같다면 종료
			{
				cout << visited[ny][nx] << '\n';
				break;
			}
			for (int j = 0; j < 8; j++) //큐에서 뽑은 위치를 8방향으로 검사해서 큐에 집어넣음
			{
				int nny = ny + mY[j];
				int nnx = nx + mX[j];
				if (nny >= 0 && nny < boardLen && nnx >= 0 && nnx < boardLen && !visited[nny][nnx])
				{
					q.push(make_pair(nny, nnx));
					visited[nny][nnx] = visited[ny][nx] + 1;
				}
			}
		}
	}
}