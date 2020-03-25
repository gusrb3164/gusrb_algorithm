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
	}//�ش� ���� ����־ ����ĥ�ߴٸ� ���� ���� �̾��� ������ ���� �ٽ� ��ͷ�Ž��.
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
		_init(V); //�޸� �ʱ�ȭ �Լ�
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
				DFS(1, j);	//Ž���Ϸ��� ���� �湮���� �ʾҰ�, ������ �̾��� ���� ������쿡�� DFS����
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