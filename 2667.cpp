#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int house[25][25]; //0은 빈곳 1은 집 -1은 체크가 끝난 집
int n; //지도크기
vector <int> result; //각 단지내 집의 수
int houseCount = 0; //총 단지수
void isNeighbor(int i, int j, int* count);
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		for (int j = 0; j < n; j++)
		{
			house[i][j] = s[j] - '0';
		}
	}//하우스 배열에 지도내용 저장
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int count = 0; //단지내 집의 수
			isNeighbor(i, j, &count);
			//조사가 안된 단지가 있을경우 단지값을 result에 삽입
			if (count > 0)
			{
				houseCount++;
				result.push_back(count);
			}
		}
	}
	sort(result.begin(), result.end());
	cout << houseCount << endl;
	for (int i = 0; i < houseCount; i++)
		cout << result[i] << endl;
}
void isNeighbor(int i, int j, int *count)
{
	if ((i < 0) || (j < 0) || (i > n - 1) || (j > n - 1))
		return;
	if (house[i][j] == 0 || house[i][j] == -1)
		return;
	house[i][j] = -1;
	(*count)++;
	isNeighbor(i - 1, j, count);
	isNeighbor(i + 1, j, count);
	isNeighbor(i, j + 1, count);
	isNeighbor(i, j - 1, count);
}