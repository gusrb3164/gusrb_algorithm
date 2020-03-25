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
		initialize(boardLen);  //�������� ũ�⸦ �Է¹ް� ũ�⸸ŭ �湮Ƚ���迭�� 0���� �ʱ�ȭ��
		cin >> y >> x;
		cin >> resultY >> resultX;
		q.push(make_pair(y, x)); //�� ó�� ��ġ�� ť�� ����
		while (1)
		{
			int ny = q.front().first;
			int nx = q.front().second;
			q.pop();
			if (ny == resultY && nx == resultX)//ť���� ���� ��ġ�� �������� ���ٸ� ����
			{
				cout << visited[ny][nx] << '\n';
				break;
			}
			for (int j = 0; j < 8; j++) //ť���� ���� ��ġ�� 8�������� �˻��ؼ� ť�� �������
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