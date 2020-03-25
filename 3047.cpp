#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	string sqce;
	int arr[3];
	cin >> arr[0] >> arr[1] >> arr[2];
	cin >> sqce;

	int temp;
	for (int i = 0; i < 2; i++)
	{
		for (int j = i+1; j <= 2; j++)
		{
			if (arr[i] > arr[j])
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
	
	for (int i = 0; i < 3; i++)
	{
		if (sqce[i] == 'A')
			cout << arr[0] << " ";
		else if (sqce[i] == 'B')
			cout << arr[1] << " ";
		else
			cout << arr[2] << " ";

	}
}