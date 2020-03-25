#include<iostream>
#include<algorithm>

using namespace std;
int arr[2][100000];
int dp[2][100000];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	
	for (int i = 0; i < T; i++)
	{
		int n;
		cin >> n;
		int j;
		for (j = 0; j < n; j++)
		{
			cin >> arr[0][j];
		}
		for (j = 0; j < n; j++)
		{
			cin >> arr[1][j];
		}
		dp[0][0] = arr[0][0];
		dp[1][0] = arr[1][0];
		dp[0][1] = arr[0][1] + arr[1][0];
		dp[1][1] = arr[0][0] + arr[1][1];
	
		for (j = 2; j < n; j++)
		{
			dp[0][j] = arr[0][j] + max(dp[1][j - 1], dp[1][j - 2]);
			dp[1][j] = arr[1][j] + max(dp[0][j - 1], dp[0][j - 2]);
		}
		cout << max(dp[0][n - 1], dp[1][n - 1]) << endl;
	}
	
}