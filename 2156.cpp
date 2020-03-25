#include<iostream>
#include<algorithm>
using namespace std;

int balance[10001];
int dpbal[10001];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int num;
	cin >> num;
	for (int i = 0; i < num; i++)
		cin >> balance[i];
	if (num == 1)
	{
		cout << balance[0];
		return 0;
	}
	
	dpbal[0] = balance[0];
	dpbal[1] = balance[1] + dpbal[0];
	if(num>2) dpbal[2] = max({ dpbal[1], dpbal[0] + balance[2],balance[1] + balance[2] });

	for (int i = 3; i < num; i++)
	{
		dpbal[i] = max(dpbal[i - 2] + balance[i], dpbal[i - 3] + balance[i - 1] + balance[i]);
		dpbal[i] = max(dpbal[i - 1], dpbal[i]); //그전 값이 더크는 경우를 위해 업데이트 해준다
	}
	cout << dpbal[num - 1];
}