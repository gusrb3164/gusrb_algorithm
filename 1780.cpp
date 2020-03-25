#include<iostream>
using namespace std;

int arr[2188][2188];
int mOne = 0; int pOne = 0; int zero = 0;

void recur(int size, int y, int x)
{
	int temp = arr[y][x];
	bool isSame = true;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (temp != arr[y + i][x + j])
			{
				isSame = false;
				break;
			}
		}
		if (!isSame)
			break;
	}
	if (isSame)
	{
		if (temp == -1)
			mOne++;
		else if (temp == 0)
			zero++;
		else
			pOne++;
		return;
	}
	else
	{
		int newSize = size / 3;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
				recur(newSize, y + newSize * i, x + newSize * j);
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int num;
	cin >> num;
	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < num; j++)
			cin >> arr[i][j];
	}
	recur(num, 0, 0);
	cout << mOne << "\n" << zero << "\n" << pOne;

}