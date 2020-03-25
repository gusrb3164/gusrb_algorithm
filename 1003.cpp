#include<iostream>

using namespace std;

int main()
{
	int zero[41] = { 0 };
	int one[41] = { 0 };
	zero[0] = 1;
	one[1] = 1;
	int t_case;
	cin >> t_case;
	for (int i = 2; i <= 40; i++)
	{
		zero[i] = zero[i - 1] + zero[i - 2];
		one[i] = one[i - 1] + one[i - 2];
	}
	for (int i = 0; i < t_case; i++)
	{
		int n;
		cin >> n;
		cout << zero[n] << " " << one[n] << endl;
	}
	return 0;
}
