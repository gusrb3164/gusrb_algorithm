#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
bool isPass[1001][1001];
bool isPassed[1001];
int dotCount, lineCount, startDot;
queue <int> q;
void DFS(int idx)
{
	cout << idx << " ";
	for (int i = 1; i <= dotCount; i++)
	{
		if (isPass[idx][i] && !isPassed[i])
		{
			isPassed[i] = true;
			DFS(i);//이동한 노드에서의 DFS다시 실행
		}
	}
}
void BFS(int idx)
{
	q.push(idx);
	isPassed[idx] = true;

	while (!q.empty())
	{
		idx = q.front();
		q.pop();
		cout << idx << " ";
		for (int i = 1; i <= dotCount; i++)
		{
			if (isPass[idx][i] && !isPassed[i])
			{
				isPassed[i] = true;
				q.push(i);
			}
		}
	}
}
int main()
{
	cin >> dotCount >> lineCount >> startDot;
	
	for (int i = 0; i < lineCount; i++)
	{
		int a, b;
		cin >> a >> b;
		isPass[a][b] = true;
		isPass[b][a] = true;
	}
	isPassed[startDot] = true;
	DFS(startDot);
	cout << endl;

	memset(isPassed, false, sizeof(isPassed));
	BFS(startDot);
}