#include<iostream>

using namespace std;
int upper[201];
int N, M;
int trip[1000];
int FindRoot(int x) //연결돼 있는 루트노드 찾는 함수
{
	if (upper[x] == x)return x;
	return upper[x] = FindRoot(upper[x]);
}
void Union(int a, int b) //b를 a아래 노드로 넣는다.
{
	a = FindRoot(a);
	b = FindRoot(b);
	upper[b] = a;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	for (int i = 1; i <= N; i++)
		upper[i] = i;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			int x;
			cin >> x;
			if (x && FindRoot(i) != FindRoot(j)) //길이 있는데 루트노드가 다르면 합친다
				Union(i, j);
		}
	}
	int temp;
	cin >> temp; //첫 번째 경로 입력받아서 root 기록
	temp = FindRoot(temp);
	//그 후에 M-1 개의 나머지 경로 검사
	for (int i = 1; i < M; i++)
	{
		int temp2;
		cin >> temp2;
		if (temp != FindRoot(temp2))
		{
			cout << "NO" << endl;
			return 0;
		}
	}
	cout << "YES" << endl;
}