#include<iostream>
using namespace std;

int main()
{
	long long int n;
	cin >> n;
	if (n >= 1500000)
	{
		n = n % 1500000;
	}
	if (n == 0)
	{
		cout << 0;
		return 0;
	}
	else if (n == 1)
	{
		cout << 1;
		return 0;
	}
	int fibo[3];

	fibo[0] = 0;
	fibo[1] = 1;
	for (int i = 2; i <= n; i++)
	{
		fibo[2] = (fibo[0] + fibo[1]) % 1000000;
		fibo[0] = fibo[1];
		fibo[1] = fibo[2];
	}
	cout << fibo[2];

}