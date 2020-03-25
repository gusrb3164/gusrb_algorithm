#include<iostream>
using namespace std;

int main()
{
	int semester;
	int subject;
	float sumScore;
	int sumGrade;
	cin >> semester;
	for (int i = 0; i < semester; i++)
	{
		cin >> subject;
		sumScore = 0;
		sumGrade = 0;
		for (int j = 0; j < subject; j++)
		{
			float score;
			int grade;
			cin >> grade >> score;
			sumGrade += grade;
			sumScore += (grade * score);
		}
		cout << sumGrade << " " << sumScore / sumGrade << endl;
	}
}