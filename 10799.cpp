#include<iostream>
using namespace std;

char stick[100001];
int main()
{
	cin >> stick;
	int flag = -1;
	int num = 0;
	int i = 0;
	while(stick[i]!=NULL)
	{
		if (stick[i] == '(')
		{
			flag++;
			i++;
			if (stick[i] == ')') //레이져일때
			{
				num += flag;
				flag--;
				i++;
			}
		}

		else if (stick[i] == ')') //막대기 끝부분
		{
			flag--;
			i++;
			num++;
		}
	}

	cout << num;
	return 0;
}