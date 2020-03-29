//다익스트라 알고리즘 + 우선순위 큐 어렵다..
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int V, E;
vector <pair<int, int>> road[20001];
const int INF = 987654321;

vector<int> Dijkstra(int start)
{
	vector<int> minRoot(V + 1, INF); //각지점까지 가는 최소경로비용 배열
	priority_queue <pair<int, int>>pq; //<지점까지의 비용, 현재지점> 비용에 따른 우선순위큐 이므로 비용을 먼저 저장
	pq.push(make_pair(0, start));
	minRoot[start] = 0; //시작지점 경로비용은 0
	while (!pq.empty())
	{
		int position = pq.top().second;
		int cost = -pq.top().first; //우선순위가 음수로 저장되있기때문에 다시 양수로 변환
		pq.pop();
		if (minRoot[position] < cost)  //이미 저장된 비용보다 크거나 같으면 최단경로가 아니므로 버림
			continue;
		for (int i = 0; i < road[position].size(); i++) //현재위치에서 간선들의 개수만큼 pq에 들어갈 수 있는지 검사한다.
		{
			int next = road[position][i].first;
			int nextCost= cost + road[position][i].second;

			if (nextCost < minRoot[next])  //다음 지점에 있는 비용보다 지금 계산하려는 비용이 더작으면 pq에 넣는다.
			{
				minRoot[next] = nextCost; //최소경로비용 업데이트
				pq.push(make_pair(-nextCost, next)); //큰값이 우선순위이기 때문에 최소비용을 top에 넣으려면 음수로 저장
			}
		}
	}
	return minRoot;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int start;
	cin >> V >> E;
	cin >> start;
	for (int i = 0; i < E; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		road[u].push_back(make_pair(v,w));
	}

	vector<int> result = Dijkstra(start);

	for (int i = 1; i <= V; i++) //최소경로가 INF값이면 갈 수 없으므로 INF출력
	{
		if (result[i] == INF)
			cout << "INF" << endl;
		else
			cout << result[i] << endl;
	}
	return 0;
}