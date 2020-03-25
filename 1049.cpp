#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int set, each;
	int minSet = 10000000;
	int minEach = 10000000;
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> set >> each;
		minSet = min(minSet, set);
		minEach = min(minEach, each);
	}
	
	cout << min({ minSet * (N / 6 + 1),minSet * (N / 6) + minEach * (N % 6),minEach * N });
}