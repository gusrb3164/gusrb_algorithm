//���ͽ�Ʈ�� �˰��� + �켱���� ť ��ƴ�..
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int V, E;
vector <pair<int, int>> road[20001];
const int INF = 987654321;

vector<int> Dijkstra(int start)
{
	vector<int> minRoot(V + 1, INF); //���������� ���� �ּҰ�κ�� �迭
	priority_queue <pair<int, int>>pq; //<���������� ���, ��������> ��뿡 ���� �켱����ť �̹Ƿ� ����� ���� ����
	pq.push(make_pair(0, start));
	minRoot[start] = 0; //�������� ��κ���� 0
	while (!pq.empty())
	{
		int position = pq.top().second;
		int cost = -pq.top().first; //�켱������ ������ ������ֱ⶧���� �ٽ� ����� ��ȯ
		pq.pop();
		if (minRoot[position] < cost)  //�̹� ����� ��뺸�� ũ�ų� ������ �ִܰ�ΰ� �ƴϹǷ� ����
			continue;
		for (int i = 0; i < road[position].size(); i++) //������ġ���� �������� ������ŭ pq�� �� �� �ִ��� �˻��Ѵ�.
		{
			int next = road[position][i].first;
			int nextCost= cost + road[position][i].second;

			if (nextCost < minRoot[next])  //���� ������ �ִ� ��뺸�� ���� ����Ϸ��� ����� �������� pq�� �ִ´�.
			{
				minRoot[next] = nextCost; //�ּҰ�κ�� ������Ʈ
				pq.push(make_pair(-nextCost, next)); //ū���� �켱�����̱� ������ �ּҺ���� top�� �������� ������ ����
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

	for (int i = 1; i <= V; i++) //�ּҰ�ΰ� INF���̸� �� �� �����Ƿ� INF���
	{
		if (result[i] == INF)
			cout << "INF" << endl;
		else
			cout << result[i] << endl;
	}
	return 0;
}