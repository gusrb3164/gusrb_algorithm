#include<iostream>
#include<algorithm>
using namespace std;
int T, W;
int position[3][1001]; // 나무위치,자두순서
int dp[3][1001][32]; //나무위치,자두순서,움직인 횟수

int _dp()
{
	// 처음 움직인횟수를 0이아닌 1로 설정(j-1이 -1이 나올수 있으므로)
	dp[1][1][1] = position[1][1];
	dp[2][1][2] = position[2][1];
	int maxJadu = 1;
	for (int i = 2; i <= T; i++) //자두순서
 	{
		for (int j = 1; j <= W + 1; j++) //움직인 횟수
		{
			if (j > i + 1)break;
			dp[1][i][j] = max(dp[1][i - 1][j], dp[2][i - 1][j - 1]) + position[1][i];
			dp[2][i][j] = max(dp[1][i - 1][j - 1], dp[2][i - 1][j]) + position[2][i];
			maxJadu = max({ maxJadu,dp[1][i][j] ,dp[2][i][j] });
		}
	}
	return maxJadu;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> T >> W;
	for (int i = 1; i <= T; i++)
	{
		int temp;
		cin >> temp;
		position[temp][i] = 1;
	}
	cout << _dp();
	return 0;
}