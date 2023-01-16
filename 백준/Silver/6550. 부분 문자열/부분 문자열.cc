#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX 5010
#define INF 214748361
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	while (1)
	{
		string s;
		string t;
		cin >> s >> t;
		if(cin.eof()==true)
		{
			break;
		}
		int p = 0; // s문자열 포인터
		for (int i = 0; i < t.size(); i++)
		{
			if (p >= s.size())
			{
				break;
			}
			if (t[i] == s[p])
			{
				p++;
			}
		}
		if(p<s.size())
		{
			cout << "No\n";
			continue;
		}
		cout << "Yes\n";
	}
}