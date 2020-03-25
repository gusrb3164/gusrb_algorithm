#include<iostream>
#include<vector>
using namespace std;


int main()
{
	vector <int> num;
	int size;
	cin >> size;
	vector <int> max;
	for (int i = 0; i < size; i++)
	{
		int n;
		cin >> n;
		num.push_back(n);
	}

	max.push_back(num[0]);
	for (int i = 1; i < size; i++)
	{
		if ((max[i - 1] + num[i]) > num[i])
			max.push_back(max[i - 1] + num[i]);
		else
			max.push_back(num[i]);
	}

	int result = max[0];
	for (int i = 1; i < size; i++)
	{
		if (result < max[i])
			result = max[i];
	}
	cout << result;
	return 0;
}