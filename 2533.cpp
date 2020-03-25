#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;
const int MAX = 1000001;
int nodeNum;
vector<int> node[MAX];
int dp[1000001][2];//0�϶��� �󸮾���� x 1�϶��� �󸮾����

int DP(int prev, int now, bool isEly)
{
	int &temp = dp[now][isEly]; //temp�� ����dp�� ���Ͻ���
	if (temp != -1)
		return temp;

	temp = 0; //temp �� �ڽĳ����� �ּ� ����� ���� ��� ���ҿ���
	for (int i = 0; i < node[now].size(); i++)
	{
		int next = node[now][i];
		if (next == prev)  //�θ�� ���±��̸� ��Ƽ��
			continue;
		if (isEly) //�ٷξƷ� �ڽĳ����� ��� ����
			temp += min(DP(now, next, 0), DP(now, next, 1) + 1);
		else //�θ� �󸮾���Ͱ� �ƴϸ� �ٷξƷ� �ڽĵ��� �� �����
			temp += DP(now, next, 1) + 1;
	}
	return temp;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> nodeNum;
	for (int i = 0; i < nodeNum - 1; i++)
	{
		int node1, node2;
		cin >> node1 >> node2;
		node[node1].push_back(node2);
		node[node2].push_back(node1);
	}
	memset(dp, -1, sizeof(dp));
	
	cout << min(DP(-1, 1, 0), DP(-1, 1, 1) + 1) << endl;
	return 0;
}