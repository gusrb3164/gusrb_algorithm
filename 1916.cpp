#include<iostream>
#include<vector>
#include<queue>
using namespace std;
const int MAX = 987654321;
int N, M;
vector <int> minCost(1001, MAX);
vector<pair<int, int>>city[1001]; //도시에서 출발하는 버스 배열
int Dijkstra(int start, int end)
{
	minCost[start] = 0;
	priority_queue<pair<int, int>>pq;//(비용, 위치)
	pq.push(make_pair(0, start));
	while (!pq.empty())
	{
		int cost = -pq.top().first; //음수로 치환한 비용을 다시 양수로 치환
		int now = pq.top().second;
		pq.pop();
		if (minCost[now] < cost)
			continue;
		for (int i = 0; i < city[now].size(); i++)
		{
			int nextCost = cost + city[now][i].first;
			int next = city[now][i].second;
			if (nextCost < minCost[next]) //이미 저장된 비용보다 작을경우 큐에 넣음
			{
				minCost[next] = nextCost;
				pq.push(make_pair(-nextCost, next));
			}
		}
	}
	return minCost[end];
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		int start, end, cost;
		cin >> start >> end >> cost;
		city[start].push_back(make_pair(cost, end));
	}
	int start, end;
	cin >> start >> end;
	
	cout << Dijkstra(start, end) << endl;
	return 0;
}