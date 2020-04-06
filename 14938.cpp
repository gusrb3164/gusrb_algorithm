#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

vector <pair<int, int>>road[101];//<���, �ش���ġ>
int item[101];
int isVisited[101];
int n, m, r;//������ ����, ��������, ���� ����
const int INF = 987654321;
int sum_item(int start)
{
	int sum = item[start]; //�湮�ߴ� �������� item�� ���� ����
	priority_queue <pair<int, int>>pq; 
	pq.push(make_pair(0, start));

	while (!pq.empty())
	{
		int sumRoad = -pq.top().first; //�켱����ť�� ������ ���������Ƿ� �ٽ� ����� ġȯ.
		int posi = pq.top().second;
		pq.pop();
		if (sumRoad > isVisited[posi]) continue; //�ּ� ��ΰ� �ƴϸ� continue
		isVisited[posi] = sumRoad; //q���� ���� �湮������ true�ٲ۴�.
		
		for (int i = 0; i < road[posi].size(); i++)
		{
			int nextRoad = sumRoad + road[posi][i].first;
			int nextPosi = road[posi][i].second;
			if (nextRoad > m || nextRoad > isVisited[nextPosi])
				continue;
			else
			{
				if (isVisited[nextPosi] == INF) //���� �湮���� ���̸� �������� ����
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
		road[t1].push_back(make_pair(t3, t2)); //������ ���� �Է�
		road[t2].push_back(make_pair(t3, t1));
	}
	int sumMax = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++) //���������� �ٲܶ����� �ּҰ�θ� �ʱ�ȭ ���ش�.
			isVisited[j] = INF;
		sumMax = max(sumMax, sum_item(i));
	}
	cout << sumMax << endl;
	return 0;
}