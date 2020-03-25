#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int house[25][25]; //0�� ��� 1�� �� -1�� üũ�� ���� ��
int n; //����ũ��
vector <int> result; //�� ������ ���� ��
int houseCount = 0; //�� ������
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
	}//�Ͽ콺 �迭�� �������� ����
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int count = 0; //������ ���� ��
			isNeighbor(i, j, &count);
			//���簡 �ȵ� ������ ������� �������� result�� ����
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