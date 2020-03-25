#include<iostream>
#include<string>
using namespace std;

int main()
{
	int flag = 0;
	int index;
	int arr[26] = { 0 };
	int max = 0;
	string s;
	cin >> s;
	int size = s.size();
	for (int i = 0; i < size; i++)
		s[i] = toupper(s[i]);
	for (int i = 0; i < size; i++)
	{
		arr[s[i] - 'A']++;
	}

	for (int i = 0; i < 26; i++)
	{
		if (max < arr[i])
		{
			flag = 1;
			index = i;
			max = arr[i];
		}
		else if (max == arr[i])
		{
			flag = 0;
		}
	}
	char result = index + 'A';
	if (flag == 0)
		cout << "?" << endl;
	else
		cout << result;
}