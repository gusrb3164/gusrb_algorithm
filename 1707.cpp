#include<iostream>
#include<vector>
using namespace std;
int isColor[20001];//-1,1:color ,0:not visit
vector<int> graph[20001];
bool flag = true;
void DFS(int color,int dot)
{
	if (isColor[dot] == color)
		return;
	else if (isColor[dot] == 0)
		isColor[dot] = color;
	else
	{
		flag = false;
		return;
	}//해당 점이 비어있어서 색을칠했다면 이제 점에 이어진 선들을 통해 다시 재귀로탐색.
	for (int i = 0; i < graph[dot].size(); i++)
		DFS(color * -1, graph[dot][i]);
	
}
void _init(int V)
{
	flag = true;
	for (int i = 1; i <= V ; i++)
	{
		graph[i].clear();
		isColor[i] = 0;
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t_case;
	int V, E;
	cin >> t_case;

	for (int i = 0; i < t_case; i++)
	{
		cin >> V >> E;
		_init(V); //메모리 초기화 함수
		for (int j = 0; j < E; j++)
		{
			int n1, n2;
			cin >> n1 >> n2;
			graph[n1].push_back(n2);
			graph[n2].push_back(n1);
		}
		for (int j = 1; j <= V; j++)
		{
			if (!isColor[j] && !graph[j].empty())
				DFS(1, j);	//탐색하려는 점이 방문하지 않았고, 주위에 이어진 선이 있을경우에만 DFS실행
			if (!flag)
			{
				cout << "NO" << '\n';
				break;
			}
		}
		if (flag)
			cout << "YES" << '\n';
	}
}// 5 2 1 2 2 5