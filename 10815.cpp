#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N, M;
vector <int>vn;
vector <int>vm;
void binary_search(int n)
{
	int mi = 0;
	int ma = N - 1;
	while (1)
	{
		int idx = (mi + ma) / 2;
		if (vn[idx] > n)
			ma = idx;
		else if (vn[idx] < n)
			mi = idx;
		else
		{
			cout << 1 << " ";
			return;
		}
		if (ma - mi <= 1)
		{
			if (n == vn[ma])
			{
				cout << 1 << " ";
				return;
			}
			else if (n == vn[mi])
			{
				cout << 1 << " ";
				return;
			}
			else
			{
				cout << 0 << " ";
				return;
			}
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;
		vn.push_back(temp);
	}
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		int temp;
		cin >> temp;
		vm.push_back(temp);
	}
	sort(vn.begin(), vn.end());

	for (int i = 0; i < M; i++)
	{
		binary_search(vm[i]);
	}
}