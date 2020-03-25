#include<iostream>

using namespace std;

int main()
{
	int max;
	int in[4];
	int out[4];
	for (int i = 0; i < 4; i++)
	{
		cin >> out[i] >> in[i];
	}
	int people[3];
	people[0] = in[0];
	people[1] = people[0] - out[1] + in[1];
	people[2] = people[1] - out[2] + in[2];

	max = people[0];
	for (int i = 1; i <= 2; i++)
	{
		if (people[i] > max)
			max = people[i];
	}
	cout << max << endl;
}