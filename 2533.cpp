#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;
const int MAX = 1000001;
int nodeNum;
vector<int> node[MAX];
int dp[1000001][2];//0일때는 얼리어답터 x 1일때는 얼리어답터

int DP(int prev, int now, bool isEly)
{
	int &temp = dp[now][isEly]; //temp를 현재dp와 동일시함
	if (temp != -1)
		return temp;

	temp = 0; //temp 에 자식노드들의 최소 어답터 수를 모두 더할예정
	for (int i = 0; i < node[now].size(); i++)
	{
		int next = node[now][i];
		if (next == prev)  //부모로 가는길이면 컨티뉴
			continue;
		if (isEly) //바로아래 자식노드들의 경로 더함
			temp += min(DP(now, next, 0), DP(now, next, 1) + 1);
		else //부모가 얼리어답터가 아니면 바로아래 자식들은 얼리 어답터
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