#include<iostream>
#include<algorithm>
int wood[1000001];
using namespace std;
int N, M;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	for (int i = 1; i <= N; i++)
		cin >> wood[i];
	sort(wood + 1, wood + N + 1);  //������ ���� �������� ����
	int idx = N;
	long long int sum = 0;
	while (1)
	{
		sum += (long long int)(wood[idx] - wood[idx - 1]) * (N - idx + 1);
		if (sum > M)
			break;
		else if (sum == M)
		{
			cout << wood[idx - 1];
			return 0;
		}
		idx--;
	}
	//idx-1������ idx���� ������ ���̰� result��°� �˰Ե�.
	int cnt = N - idx + 1; //�ڸ� ������ ����
	long long int temp = sum - M;
	temp = temp / cnt;
	//temp= wood[idx-1]���� �� �ø� ����
	sum = sum - temp * cnt;
	if (sum < M)
		temp = temp - 1;

	int result = temp + wood[idx - 1];
	cout << result << endl;
}