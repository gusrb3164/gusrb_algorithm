#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int arr[4][4001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<int> v1;
	vector<int> v2;
	for (int i = 0; i < n; i++)
		cin >> arr[0][i] >> arr[1][i] >> arr[2][i] >> arr[3][i];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			v1.push_back(arr[0][i] + arr[1][j]);
			v2.push_back(arr[2][i] + arr[3][j]);
		}
	}
	sort(v1.begin(), v1.end()); //0,1번배열을 먼저 더해서 오름차순 정렬함.
	sort(v2.begin(), v2.end());
	long long int cnt = 0;
	int idx1 = 0;
	int idx2 = n * n - 1;
	while (idx1 < n * n && idx2 >= 0)
	{
		if (v1[idx1] + v2[idx2] > 0)
			idx2--;
		else if (v1[idx1] + v2[idx2] < 0)
			idx1++;
		else //합이 0이라면 v1배열중 같은수와 v2배열중 같은수 개수의 곱만큼 더하고 인덱스를 이동시킨다.
		{
			long long int v1cnt = 1;
			long long int v2cnt = 1;
			while ((idx1 + 1) < n * n && v1[idx1] == v1[idx1 + 1])
			{
				v1cnt++;
				idx1++;
			}
			while ((idx2 - 1) >= 0 && v2[idx2] == v2[idx2 - 1])
			{
				v2cnt++;
				idx2--;
			}
			cnt += v1cnt * v2cnt;
			idx1++; idx2--;
		}
	}

	cout << cnt << endl;
}