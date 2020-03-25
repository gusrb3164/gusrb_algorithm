#include<iostream>
using namespace std;
int main()
{
	int money;
	cin >> money;
	money = 1000 - money;
	int count = 0;
	int temp;
	if (money >= 500)
	{
		temp = money / 500;
		count += temp;
		money -= 500 * temp;
	}
	if (money >= 100)
	{
		temp = money / 100;
		count += temp;
		money -= 100 * temp;
	}
	if (money >= 50)
	{
		temp = money / 50;
		count += temp;
		money -= 50 * temp;
	}
	if (money >= 10)
	{
		temp = money / 10;
		count += temp;
		money -= 10 * temp;
	}
	if (money >= 5)
	{
		temp = money / 5;
		count += temp;
		money -= 5 * temp;
	}
	if (money >= 1)
	{
		temp = money;
		count += temp;
		money -= temp;
	}
	cout << count;
}