#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
	vector<int> v;
	string num;
	cin >> num;
	int flag = 0;
	int len = num.size();
	int sum = 0; 

	for (int i = 0; i < len; i++)
	{
		v.push_back(num[i] - '0');
		if (num[i] == '0')
			flag = 1;
		sum += (num[i] - '0');
	}

	if (flag == 1 && sum % 3 == 0)
	{
		sort(v.begin(), v.end());
		for (int i = len - 1; i >= 0; i--)
			cout << v[i];
	}
	else
		cout << -1;
}