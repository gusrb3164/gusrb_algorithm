#include<iostream>
#include<algorithm>
using namespace std;
int n, k;
int dp[10001];//dp[���簡��]=�ּҰ���
int coin[101];//�ش� ������ ��ġ

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
		for (int j = coin[i]; j <= k; j++)	//���ο� ������ �߰��� �� ���� �ּڰ��� ������Ʈ ��.
		{
			dp[j] = min(dp[j - coin[i]] + 1, dp[j]); //j���ݿ��� ���� ����ŭ �� �ּҰ���+1�� 
		}											 //����j���� �ּҰ����� �ּҰ��� ����.
	}

	if (dp[k] == 10001)
		cout << -1 << endl;
	else
		cout << dp[k] << endl;
	return 0;
}