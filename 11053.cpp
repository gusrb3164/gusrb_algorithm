#include<iostream>
#include<algorithm>
using namespace std;
int arr[1000];
int dp[1000];
int result = 0;
int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	for (int i = 0; i < n; i++)
	{
		dp[i] = 1; //�׻� ������ 1���� ����
		for (int j = 0; j < i; j++) //���� �������� ���� ũ�ٸ� ���������� ������ +1�Ѱ��� ���Ѵ�.
		{
			if (arr[i] > arr[j])
			{
				dp[i] = max(dp[j] + 1, dp[i]);
			}
		}
		result = max(result, dp[i]);
	}
	cout << result;
}