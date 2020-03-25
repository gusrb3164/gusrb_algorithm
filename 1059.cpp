#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main()
{
	vector <int> v;
	int L;
	int N;
	int temp;
	cin >> L;

	for (int i = 0; i < L; i++)
	{
		cin >> temp;
		v.push_back(temp);
	}
	cin >> N;
	sort(v.begin(), v.end());

	int i = 0;
	while (true)
	{
		if (N == v[i])
		{
			cout << 0;
			return 0;
		}
		if (N < v[i])
			break;
		i++;
	}
	if (i == 0)
	{
		if (v[i] - N == 0)
		{
			cout << 0;
			return 0;
		}
		int max = v[i] - N - 1;
		int min = N - 1;
		int result = max + min + max * min;
		cout << result;
		return 0;
	}
	//v[i-1]~N~v[i]
	int max = v[i] - N - 1;
	int min = N - v[i - 1] - 1;
	if (max <= 0)
		max = 0;
	if (min <= 0)
		min = 0;

	int result = max * min + max + min;
	cout << result;
}