#include<iostream>

using namespace std;

int main()
{
	int fe, ma, intan;
	cin >> fe >> ma >> intan;

	int N = fe;
	int M = ma;

	while (intan != 0)
	{
		if (N > 2 * M)
			N--;
		else
			M--;
		if (N < 2 || M < 1)
		{
			cout << 0;
			return 0;
		}
		intan--;
	}
	
	int count = 0;
	while (N >= 2 && M >= 1)
	{
		N -= 2;
		M--;
		count++;
	}
	cout << count;
}