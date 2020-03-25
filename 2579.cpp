#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int dp_max[300] = { 0 };
	int arr[300] = { 0 };
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	if (n == 1)
	{
		cout << arr[0];
		return 0;
	}
	else if (n == 2)
	{
		cout << arr[1] + arr[0];
		return 0;
	}
	dp_max[0] = arr[0];
	dp_max[1] = arr[1]+arr[0];
	dp_max[2] = max(arr[0] + arr[2], arr[1] + arr[2]);
	for (int i = 3; i < n; i++)
	{
		dp_max[i] = max(dp_max[i - 2] + arr[i], dp_max[i - 3] + arr[i - 1] + arr[i]);
	}
	cout << dp_max[n - 1];
	return 0;
}