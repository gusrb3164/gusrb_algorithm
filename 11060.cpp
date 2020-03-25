#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
int minJump[1001];
int miro[1001];
int main()
{
	queue<pair<int, int>>q; //<idx,jumpSize>
	int size;
	cin >> size;
	for (int i = 1; i <= size; i++)
		cin >> miro[i];
	for (int i = 1; i <= size; i++)
		minJump[i] = 20000;
	minJump[1] = 0;  //���� ����Ƚ��
	int idx = 1;  //���� ��ġ
	q.push(make_pair(1, miro[1]));

	while (!q.empty())
	{
		idx = q.front().first;
		int jumpSize = q.front().second;
		if (idx == size)
			break;
		q.pop();

		for (int i = 1; i <= jumpSize; i++)
		{
			if (idx + i > size)continue; //������ ��ġ�� size���� Ŀ������ ���
			if (minJump[idx] + 1 < minJump[idx + i])
			{
				minJump[idx + i] = minJump[idx] + 1;
				q.push(make_pair(idx + i, miro[idx + i]));
			}
		}
	}
	
	if (idx == size)
		cout << minJump[idx];
	else
		cout << -1;
}