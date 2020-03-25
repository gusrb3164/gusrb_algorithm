#include<iostream>
#include<deque>
using namespace std;

int main()
{
	long long int sum = 0;
	int size;
	cin >> size;
	deque<int> q;
	for (int i = 0; i < size; i++)
	{
		int temp;
		cin >> temp;
		if (temp != 0)
			q.push_back(temp);
		else
			q.pop_back();
	}
	while (!q.empty())
	{
		sum += q.front();
		q.pop_front();
	}
	cout << sum;
}