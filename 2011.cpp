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
	for (int i = 0; i < codeLen; i++) // 1���ڸ����� ����
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
		//26���� ū ���� ����Ǽ��� �ϳ����̴�.
		else if (code[i] * 10 + code[i - 1] > 26)
		{
			if (code[i-1]==0) //30�̻� 10�ǹ���ϰ�� �Ұ����� ����̹Ƿ� 0�� ����Ѵ�.
			{
				cout << 0 << endl;
				return 0;
			}
			dp[i] = dp[i - 1];
		}
		//26���� ���� ���� 2�����̴�.
		else
		{
			dp[i] = dp[i - 1] + dp[i - 2];
		}
		dp[i] = dp[i] % 1000000;
	}
	cout << dp[codeLen - 1] << endl;
	return 0;
}