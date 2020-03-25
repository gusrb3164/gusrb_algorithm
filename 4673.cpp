#include<iostream>

using namespace std;
int arr[10050] = { 0 };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int sum;
	int temp;
	int num = 1;
	while (1)
	{
		temp = num;
		sum = temp;
		while (1)
		{
			sum += (temp % 10);
			temp /= 10;
			if (temp == 0)
				break;
		}
		
		arr[sum]++;
		num++;
		if (num > 9990)
			break;
	}
	for (int i = 1; i <= 10000; i++)
	{
		if (arr[i] == 0)
			cout << i << "\n";
	}
}