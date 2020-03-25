#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
int main()
{
	vector <int> time;
	int N;
	cin >> N;
	int sum = 0;
	for (int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;
		time.push_back(temp);
	}

	sort(time.begin(), time.end());

	for (int i = 0; i < N; i++)
	{
		sum += time[i];
		for (int j = 0; j < i; j++)
			sum += time[j];
	}

	cout << sum;
}