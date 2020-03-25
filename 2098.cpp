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
	if (visited == (1 << N) - 1)//��� ���� ��Ʈ�� �� �����ٸ� 0������ ���°� ��ȯ
	{
		if (city[now][0] != 0)
			return city[now][0];
	}
	int &result = cache[now][visited];
	if (result != -1)  //���ݱ��� �湮�� ���ð� �������̸� ����
		return result;
	result = INF;
	for (int next = 0; next < N; next++)
	{
		if (visited & (1 << next) || city[now][next] == 0)
			continue; // ���� �� ���ð� �湮�߰ų� ��ΰ� ���ٸ� ��Ƽ��
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

