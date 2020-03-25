#include<iostream>
#include<deque>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N, K;
	cin >> N >> K;
	string s;
	cin >> s;
	int count = K;
	int idx = 0;  //21921
	deque <char> dq;
	for (int i = 0; i < s.size(); i++)
	{
		while (count > 0 && !dq.empty() && dq.back() < s[i])
		{
			dq.pop_back();
			count--;
		}
		dq.push_back(s[i]);
	}
	
	for (int i = 0; i < dq.size() - count; i++)
		cout << dq[i];
}