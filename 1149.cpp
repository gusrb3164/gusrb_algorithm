#include<iostream>
#define MAX 1000001
using namespace std;

int houseCol[1000][3];
int minCol[1000][3];
int N;
int Min = MAX;
void DP(int level, int rgb, int sum);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> houseCol[i][0] >> houseCol[i][1] >> houseCol[i][2];
		for (int j = 0; j < 3; j++)
			minCol[i][j] = MAX;
	}
	for (int i = 0; i < 3; i++)
		minCol[0][i] = houseCol[0][i];
	for (int i = 0; i < 3; i++)
		DP(1, i, minCol[0][i]);
	cout << Min << endl;
}

void DP(int level, int rgb, int sum)
{
	if (level == N)
	{
		if (Min > sum)
			Min = sum;
		return;
	}
	for (int i = 0; i < 3; i++)
	{
		if (i == rgb)continue;

		if (minCol[level][i] < houseCol[level][i] + sum)
			continue;
		minCol[level][i] = sum + houseCol[level][i];
		DP(level + 1, i, minCol[level][i]);
	}
}