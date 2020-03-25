#include<iostream>
#include<algorithm>
using namespace std;
int arr[500][500];
int dp[500][500];//�ش���ġ���� �����ҋ� ��ƿ�� �ִ� �ִ� ���� ����.
int n;
int dy[4] = { 0,0,-1,1 };
int dx[4] = { 1,-1,0,0 };
//DFS�� �ϵ� DP�� �̿��� �ݺ�Ƚ���� �ٿ����Ѵ�.
//�ִ볯�� ������ִ°����� ������ �� ���� �볪���� �ִٸ� �� �볪���� �׹����� �ִ볯+1�� �����ָ� �ȴ�.
int search(int y, int x)
{
	if (dp[y][x]) //�ش���ġ�� ���� �ִٸ� ������ �ش���ġ���� �ִ��� �̹� Ž���� ���̹Ƿ� ����.
		return dp[y][x];

	dp[y][x] = 1; //���� �鸥���� �ƴϸ� �ϴ� �Ϸ�� ����
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= n || nx >= n)
			continue;
		if (arr[y][x] >= arr[ny][nx]) //�ű���� ������ �볪������ �������� continue
			continue;
		//�����ִ� ����Ǽ����� �ִ��� ���Ͽ� ������Ʈ��.
		dp[y][x] = max(dp[y][x], search(ny, nx) + 1);
	}
	return dp[y][x];
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cin >> arr[i][j];
	}

	int result = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			result = max(result, search(j, i));
		}
	}
	cout << result << endl;
}