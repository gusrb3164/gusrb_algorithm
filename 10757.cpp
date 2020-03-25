#include<iostream>

using namespace std;

string add(string& a, string& b);

int main()
{
	string A;
	string B;
	cin >> A >> B;

	int lenA = A.size();
	int lenB = B.size();
	if (lenA >= lenB)
		cout << add(A, B) << endl;
	else
		cout << add(B, A) << endl;
	return 0;
}

string add(string& a, string& b)
{
	int aSize = a.size();
	int bSize = b.size();
	string result(aSize, '0');
	int carry = 0;
	int sum;

	for (int i = 0; i < aSize; i++)
	{
		sum = 0;
		sum = sum + a[aSize - i - 1] - '0' + carry;
		if (i < bSize)
			sum = sum + b[bSize - i - 1] - '0';
		if (sum >= 10)
		{
			sum = sum - 10;
			carry = 1;
			result[aSize - i - 1] = sum + '0';
		}
		else
		{
			carry = 0;
			result[aSize - i - 1] = sum + '0';
		}
	}
	if (carry == 1)
		result = '1' + result;
	return result;
}
