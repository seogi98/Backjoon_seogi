#include <bits/stdc++.h>
using namespace std;
#define MAX 50
map<pair<int, int>, int> M[5];
int gcd(int a, int b)
{
	while (b != 0)
	{
		int r = a % b;
		a = b;
		b = r;
	}
	return a;
}
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int A, B;
		cin >> A >> B;
		int div = gcd(A, B);
		int mp;
		if (A >= 0 && B >= 0)
		{
			mp = 1;
		}
		if (A <= 0 && B >= 0)
		{
			mp = 2;
		}
		if (A <= 0 && B <= 0)
		{
			mp = 3;
		}
		if (A >= 0 && B <= 0)
		{
			mp = 4;
		}
		M[mp][{A / div, B / div}]++;
	}
	int mx = 0;
	for (int j = 1; j <= 4; j++)
	{
		for (auto i : M[j])
		{
			mx = max(i.second, mx);
		}
	}
	cout << mx;
}
