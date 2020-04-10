#include<iostream>

using namespace std;
int upper[201];
int N, M;
int trip[1000];
int FindRoot(int x) //����� �ִ� ��Ʈ��� ã�� �Լ�
{
	if (upper[x] == x)return x;
	return upper[x] = FindRoot(upper[x]);
}
void Union(int a, int b) //b�� a�Ʒ� ���� �ִ´�.
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
			if (x && FindRoot(i) != FindRoot(j)) //���� �ִµ� ��Ʈ��尡 �ٸ��� ��ģ��
				Union(i, j);
		}
	}
	int temp;
	cin >> temp; //ù ��° ��� �Է¹޾Ƽ� root ���
	temp = FindRoot(temp);
	//�� �Ŀ� M-1 ���� ������ ��� �˻�
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