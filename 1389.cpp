#include<iostream>
#include<algorithm>
using namespace std;

int user[101][101]; int N, M;
//플로이드 이해안됨;;
void floyd()
{
	for (int k = 1; k <= N; k++)
	{
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				if (i == j)continue;
				else if (user[i][k] && user[k][j])
				{
					if (user[i][j] == 0)
						user[i][j] = user[i][k] + user[k][j];
					else
						user[i][j] = min(user[i][j], user[i][k] + user[k][j]);
				}
			}
		}
	}
}
int main()
{
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		int x, y;
		cin >> x >> y;
		user[x][y] = 1;
		user[y][x] = 1;
	}
	floyd();
	int minPerson;
	int mini = 987644212;
	for (int i = 1; i <= N; i++)
	{
		int sum = 0;
		for (int j = 1; j <= N; j++)
			sum += user[i][j];
		if (sum < mini)
		{
			mini = sum;
			minPerson = i;
		}
	}

	cout << minPerson << endl;
}