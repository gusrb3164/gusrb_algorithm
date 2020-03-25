#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int dice[6];
	long long int N;
	cin >> N;
	for (int i = 0; i < 6; i++)
		cin >> dice[i];

	if (N == 1)
	{
		int sum = 0;
		int Max = dice[0];
		for (int i = 0; i < 6; i++)
		{
			Max = max(Max, dice[i]);
			sum += dice[i];
		}
		cout << sum - Max;
		return 0;
	}

	int A = dice[0]; int B = dice[1]; int C = dice[2]; int D = dice[3]; int E = dice[4]; int F = dice[5];
	int mini[3];  //다이스 노출면적 개수에 따른 최솟값

	mini[0] = dice[0];

	for (int i = 0; i < 6; i++)
		mini[0] = min(mini[0], dice[i]);
	
	mini[1] = A + B;
	mini[1] = min(mini[1], A+C);
	mini[1] = min(mini[1], A+E);
	mini[1] = min(mini[1], A+D);
	mini[1] = min(mini[1], B+D);
	mini[1] = min(mini[1], B+C);
	mini[1] = min(mini[1], D+E);
	mini[1] = min(mini[1], C+E);
	mini[1] = min(mini[1], E+F);
	mini[1] = min(mini[1], B+F);
	mini[1] = min(mini[1], C+F);
	mini[1] = min(mini[1], D+F);

	mini[2] = A + B + C;
	mini[2] = min(mini[2], A+B+D);
	mini[2] = min(mini[2], A+E+C);
	mini[2] = min(mini[2], A+E+D);
	mini[2] = min(mini[2], B+C+F);
	mini[2] = min(mini[2], B+D+F);
	mini[2] = min(mini[2], D+E+F);
	mini[2] = min(mini[2], C+E+F);

	long long int sum = mini[2] * 4 + mini[1] * (8 * N - 12) + mini[0] * (N * N * 5 - 12 - 2 * (8 * N - 12));
	cout << sum;
}