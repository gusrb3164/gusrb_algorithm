#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int K, N;
vector <long long int> lanLen;

bool desc(int a, int b)
{
	return a > b;
}

bool test(long long len)   //�־��� ���̰� �������� ���ų� Ŭ ��� true ��ȯ
{
	long long int count = 0;
	for (int i = 0; i < K; i++)
		count += lanLen[i] / len;
	return count >= N;
}
int main()
{
	cin >> K >> N;

	for (int i = 0; i < K; i++)
	{
		long long int temp;
		cin >> temp;
		lanLen.push_back(temp);
	}
	sort(lanLen.begin(), lanLen.end(), desc);
	long long int max = lanLen[0]; //���� �� ������ ���̸� �����ϴ� ����
	long long int min = 1;
	while (true)//�̺� Ž���� ���ؼ� ������ ��������
	{
		bool result = test((max + min) / 2);
		if (result)
			min = (max + min) / 2;
		else
			max = (max + min) / 2;
		if (max - min <= 1)
			break;
	}
	if (test(max))
		cout << max;
	else
		cout << min;
}