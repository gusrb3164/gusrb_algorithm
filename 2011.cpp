#include<iostream>
#include<cstring>
using namespace std;
int code[5001];
int dp[5001];
int main()
{
	char c[5001];
	cin >> c;
	int codeLen = strlen(c);
	for (int i = 0; i < codeLen; i++) // 1의자리부터 저장
		code[i] = c[codeLen - i - 1] - '0';
	if (codeLen == 1)
	{
		if (code[0] == 0)
		{
			cout << 0 << endl;
			return 0;
		}
		cout << 1 << endl;
		return 0;
	}
	if (code[0] == 0)
	{
		if (code[1] >= 3 || code[1] == 0)
		{
			cout << 0 << endl;
			return 0;
		}
		dp[0] = 0;
		dp[1] = 1;
	}
	else
	{
		dp[0] = 1;
		if (code[1] * 10 + code[0] > 26)
			dp[1] = 1;
		else if (code[1] == 0)
			dp[1] = 0;
		else
			dp[1] = 2;
	}
	

	for (int i = 2; i < codeLen; i++)
	{
		if (code[i] == 0)
		{
			dp[i] = 0;
		}
		//26보다 큰 수는 경우의수가 하나뿐이다.
		else if (code[i] * 10 + code[i - 1] > 26)
		{
			if (code[i-1]==0) //30이상 10의배수일경우 불가능한 경우이므로 0을 출력한다.
			{
				cout << 0 << endl;
				return 0;
			}
			dp[i] = dp[i - 1];
		}
		//26보다 작은 경우는 2가지이다.
		else
		{
			dp[i] = dp[i - 1] + dp[i - 2];
		}
		dp[i] = dp[i] % 1000000;
	}
	cout << dp[codeLen - 1] << endl;
	return 0;
}