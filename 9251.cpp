#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int dp[1001][1001];
int main()
{
	char c1[1001];
	char c2[1001];
	cin >> c1;
	cin >> c2;
	int c1Len = strlen(c1);
	int c2Len = strlen(c2);
	for (int i = 1; i <= c2Len; i++)
	{
		for (int j = 1; j <= c1Len; j++)
		{
			if (c1[j - 1] == c2[i - 1])
				dp[j][i] = dp[j - 1][i - 1] + 1;
			else
				dp[j][i] = max(dp[j - 1][i], dp[j][i - 1]);
		}
	}
	cout << dp[c1Len][c2Len] << endl;
}