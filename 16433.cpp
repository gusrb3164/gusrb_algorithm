#include<iostream>

using namespace std;

int main()
{
	int N;
	int x, y;
	cin >> N >> x >> y;

	if ((x + y) % 2 == 0)
	{
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				if ((i + j) % 2 == 0)
					cout << 'v';
				else cout << '.';
			}
			cout << "\n";
		}
	}

	else
	{
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				if ((i + j) % 2 == 0)
					cout << '.';
				else cout << 'v';
			}
			cout << "\n";
		}
	}
}