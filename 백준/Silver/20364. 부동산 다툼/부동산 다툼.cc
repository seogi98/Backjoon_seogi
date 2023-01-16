#include <bits/stdc++.h>
using namespace std;
#define MAX 5000000
bool tree[MAX];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N, Q;
	cin >> N >> Q;
	vector<int> V;
	for (int i = 0; i < Q; i++)
	{
		int start;
		int cur;
		cin >> cur;
		start = cur;
		int isArr = 0;
		while (cur > 1)
		{
			if (tree[cur])
			{
				isArr = cur;
			}
			cur = cur / 2;
		}
		if (isArr == 0)
		{
			tree[start] = true;
		}
		cout << isArr << "\n";
	}
}