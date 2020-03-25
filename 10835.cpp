#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int _left[2000];
int _right[2000];
int sum[2000][2000];
int num;

int recur(int Lidx, int Ridx)  //Top-Bottom ������ Dp�˰���
{
	if (Lidx == num || Ridx == num)
		return 0;
	if (sum[Lidx][Ridx] != -1) //�̹� �湮�Ѱ��� �ִ밪���� �̹� �������ֱ� ������ Pass
		return sum[Lidx][Ridx];

	sum[Lidx][Ridx] = max(recur(Lidx + 1, Ridx), recur(Lidx + 1, Ridx + 1));
	//���ʰ��� �����ʰ����� ū��� ������ ī�常 �����°�쵵 ����
	if (_left[Lidx] > _right[Ridx])
		sum[Lidx][Ridx] = max(sum[Lidx][Ridx], recur(Lidx, Ridx + 1) + _right[Ridx]);
	return sum[Lidx][Ridx];
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> num;

	for (int i = 0; i < num; i++)
	{
		cin >> _left[i];
	}
	for (int i = 0; i < num; i++)
	{
		cin >> _right[i];
	}
	
	memset(sum, -1, sizeof(sum));
	cout<<recur(0,0);
}