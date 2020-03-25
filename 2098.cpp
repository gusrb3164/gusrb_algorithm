#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const int MAX = 16;
const int INF = 987654321;

int N;
int city[MAX][MAX];
int cache[MAX][1 << MAX];

int TSP(int now, int visited)
{
	if (visited == (1 << N) - 1)//모든 도시 비트가 다 켜진다면 0번으로 가는값 반환
	{
		if (city[now][0] != 0)
			return city[now][0];
	}
	int &result = cache[now][visited];
	if (result != -1)  //지금까지 방문한 도시가 같은곳이면 리턴
		return result;
	result = INF;
	for (int next = 0; next < N; next++)
	{
		if (visited & (1 << next) || city[now][next] == 0)
			continue; // 다음 갈 도시가 방문했거나 경로가 없다면 컨티뉴
		int candidate = city[now][next] + TSP(next, visited + (1 << next));
		result = min(result, candidate);
	}
	return result;
}
int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> city[i][j];

	memset(cache, -1, sizeof(cache));
	cout << TSP(0, 1) << endl;
	return 0;
}

