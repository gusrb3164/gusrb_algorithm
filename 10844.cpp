#include<iostream>
using namespace std;
int dp[10][101];//맨 마지막 자리 수, 총 길이
int main()
{
	int n;
	cin >> n;
	long long int sum = 0;
	for (int i = 1; i < 10; i++)
		dp[i][1] = 1;
	for (int i = 2; i <= n; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (j == 0)
				dp[j][i] = dp[1][i - 1];
			else if (j == 9)
				dp[j][i] = dp[8][i - 1];
			else
				dp[j][i] = dp[j - 1][i - 1] + dp[j + 1][i - 1];
			dp[j][i] %= 1000000000;
		}
	}
	for (int i = 0; i < 10; i++)
	{
		sum += dp[i][n];
	}
	cout << sum % 1000000000 << endl;
	return 0;
}