#include<iostream>
#include<algorithm>
using namespace std;
int arr[500][500];
int dp[500][500];//해당위치에서 시작할떄 버틸수 있는 최대 날을 저장.
int n;
int dy[4] = { 0,0,-1,1 };
int dx[4] = { 1,-1,0,0 };
//DFS를 하되 DP를 이용해 반복횟수를 줄여야한다.
//최대날이 저장되있는곳에서 주위에 더 작은 대나무가 있다면 그 대나무는 네방향의 최대날+1만 비교해주면 된다.
int search(int y, int x)
{
	if (dp[y][x]) //해당위치에 값이 있다면 어차피 해당위치에서 최댓값은 이미 탐색된 것이므로 종료.
		return dp[y][x];

	dp[y][x] = 1; //아직 들른곳이 아니면 일단 하루로 설정
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= n || nx >= n)
			continue;
		if (arr[y][x] >= arr[ny][nx]) //옮기려는 지역의 대나무양이 더적으면 continue
			continue;
		//갈수있는 경우의수끼리 최댓값을 비교하여 업데이트함.
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