#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
queue <int>q;
vector <int>v;

int main()
{
	int qSize, popSize;

	cin >> qSize >> popSize;
	for (int i = 1; i <= qSize; i++)
		v.push_back(i);
	for (int i = 1; i <= popSize; i++)
	{
		int temp;
		cin >> temp;
		q.push(temp);
	}

	int sum = 0;
	int idx = 0;
	while (!q.empty())
	{
		int num = q.front();
		q.pop();
		int vSize = v.size();
		int spot = 0;
		for (int i = 0; i < vSize; i++)
		{
			if (num == v[i])
			{
				spot = i;
				break;
			}
		}
		if (spot > idx)
		{
			sum += min(spot - idx, (idx + vSize - spot));
		}
		else
		{
			sum += min(idx - spot, (spot + vSize - idx));
		}
		v.erase(v.begin() + spot);//빼낸 값을 벡터에서 삭제
		idx = spot;
		if (idx == v.size()) //만약 빼낸 값이 벡터의 마지막이면 벡터의 처음으로 이동
			idx = 0;
	}

	cout << sum;
}