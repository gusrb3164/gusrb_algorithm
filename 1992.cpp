#include<iostream>
#include<string>
using namespace std;
int arr[64][64];

void recur(int size, int y, int x)
{
	if (size == 1)
	{
		cout << arr[y][x];
		return;
	}
	int flag = arr[y][x];
	for (int i = y; i < y + size; i++)
	{
		for (int j = x; j < x + size; j++)
		{
			if (flag != arr[i][j])
			{
				flag = -1;
				break;
			}
		}
		if (flag == -1)
			break;
	}

	if (flag == -1)
	{
		cout << "("; //2->1->3->4ºÐ¸é
		recur(size / 2, y, x);
		recur(size / 2, y, x + size / 2);
		recur(size / 2, y + size / 2, x);
		recur(size / 2, y + size / 2, x + size / 2);
		cout << ")";
	}
	else
	{
		cout << flag;
		return;
	}
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		string s;
		cin >> s;
		for (int j = 0; j < N; j++)
		{
			arr[i][j] = s[j] - '0';
		}
	}

	recur(N, 0, 0);
}