#include<iostream>
#include<algorithm>
using namespace std;
int n, k;
int dp[10001];//dp[현재가격]=최소개수
int coin[101];//해당 코인의 가치

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> k;
	for (int i = 1; i <= k; i++)
		dp[i] = 10001;

	for (int i = 1; i <= n; i++)
	{
		cin >> coin[i];
		for (int j = coin[i]; j <= k; j++)	//새로운 동전이 추가될 때 마다 최솟값이 업데이트 됨.
		{
			dp[j] = min(dp[j - coin[i]] + 1, dp[j]); //j가격에서 코인 값만큼 뺀 최소개수+1과 
		}											 //현재j값의 최소개수중 최소값을 정함.
	}

	if (dp[k] == 10001)
		cout << -1 << endl;
	else
		cout << dp[k] << endl;
	return 0;
}