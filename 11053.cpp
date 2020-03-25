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
		dp[i] = 1; //항상 개수는 1부터 시작
		for (int j = 0; j < i; j++) //이전 수열보다 값이 크다면 이전수열의 개수에 +1한값을 비교한다.
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