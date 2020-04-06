#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

vector <pair<int, int>>road[101];//<비용, 해당위치>
int item[101];
int isVisited[101];
int n, m, r;//지역의 개수, 수색범위, 길의 개수
const int INF = 987654321;
int sum_item(int start)
{
	int sum = item[start]; //방문했던 지역들의 item을 더할 변수
	priority_queue <pair<int, int>>pq; 
	pq.push(make_pair(0, start));

	while (!pq.empty())
	{
		int sumRoad = -pq.top().first; //우선순위큐에 음수로 저장했으므로 다시 양수로 치환.
		int posi = pq.top().second;
		pq.pop();
		if (sumRoad > isVisited[posi]) continue; //최소 경로가 아니면 continue
		isVisited[posi] = sumRoad; //q에서 꺼내 방문했으면 true바꾼다.
		
		for (int i = 0; i < road[posi].size(); i++)
		{
			int nextRoad = sumRoad + road[posi][i].first;
			int nextPosi = road[posi][i].second;
			if (nextRoad > m || nextRoad > isVisited[nextPosi])
				continue;
			else
			{
				if (isVisited[nextPosi] == INF) //아직 방문안한 곳이면 아이템을 더함
					sum += item[nextPosi];
				isVisited[nextPosi] = nextRoad;
				pq.push(make_pair(-nextRoad, nextPosi));
			}
		}
	}
	return sum;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m >> r;
	for (int i = 1; i <= n; i++)
		cin >> item[i];
	for (int i = 0; i < r; i++)
	{
		int t1, t2, t3;
		cin >> t1 >> t2 >> t3;
		road[t1].push_back(make_pair(t3, t2)); //간선의 정보 입력
		road[t2].push_back(make_pair(t3, t1));
	}
	int sumMax = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++) //시작지점을 바꿀때마다 최소경로를 초기화 해준다.
			isVisited[j] = INF;
		sumMax = max(sumMax, sum_item(i));
	}
	cout << sumMax << endl;
	return 0;
}