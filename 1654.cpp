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

bool test(long long len)   //주어진 길이가 개수보다 같거나 클 경우 true 반환
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
	long long int max = lanLen[0]; //가장 긴 랜선의 길이를 저장하는 변수
	long long int min = 1;
	while (true)//이분 탐색을 통해서 범위를 좁혀나감
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