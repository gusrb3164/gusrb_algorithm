#include<iostream>
#include<string>
using namespace std;
bool check_str(string s);
int main()
{
	string s;

	while (1)
	{
		getline(cin, s);
		if (s == ".")
			return 0;
		if (check_str(s))
			cout << "yes" << endl;
		else
			cout << "no" << endl;
	}
}

bool check_str(string s)
{
	int len = s.size();
	int flag[100] = { 0 };  //(=1,[=2
	int i_flag = 0;
	for (int i = 0; i < len; i++)
	{
		if (s[i] == '(')
		{
			flag[i_flag] = 1;
			i_flag++;
		}
		else if (s[i] == '[')
		{
			flag[i_flag] = 2;
			i_flag++;
		}
		else if (s[i] == ')')
		{
			if (i_flag < 1 || flag[i_flag - 1] != 1)
				return false;
			i_flag--;
		}
		else if (s[i] == ']')
		{
			if (i_flag < 1 || flag[i_flag - 1] != 2)
				return false;
			i_flag--;
		}
	}
	if (i_flag != 0)
		return false;
	else return true;
}