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
			if (stick[i] == ')') //�������϶�
			{
				num += flag;
				flag--;
				i++;
			}
		}

		else if (stick[i] == ')') //����� ���κ�
		{
			flag--;
			i++;
			num++;
		}
	}

	cout << num;
	return 0;
}