#include<iostream>
using namespace std;

int main()
{
	int stack;
	int n;
	cin >> n;
	int len;
	int result;
	for (int i = 0; i < n; i++)
	{
		result = 1;
		stack = 0;
		string s;
		cin >> s;
		len = s.size();
		for (int j = 0; j < len; j++)
		{
			if (s[j] == ')')
			{
				if (stack == 0)
				{
					result = 0;
					break;
				}
				stack--;
			}
			else
			{
				stack++;
			}
		}
		if (result == 0 || stack != 0)
			cout << "NO" << endl;
		else
			cout << "YES" << endl;
	}
}