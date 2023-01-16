#include <bits/stdc++.h>
using namespace std;
#define MAX 2000
#define INF 10000001
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	while (T--)
	{

		set<int> S;
		int l, n;
		cin >> l >> n;
		for (int i = 0; i < n; i++)
		{
			int tmp;
			cin >> tmp;
			S.insert(tmp);
		}
		int mid = l / 2;
		set<int>::iterator tmp = S.upper_bound(mid);
		set<int>::iterator tmp2 = tmp;
		pair<int, int> ans;
		if (tmp == S.begin())
		{
			ans.first = l-*tmp;
		}
		if(tmp == S.end()){
			tmp--;
			ans.first = *tmp;
		}
		else
		{
			tmp2--;
			ans.first = max(l - *tmp, *tmp2);
		}
		ans.second = max(l - *S.begin(), *(--S.end()));
		cout << ans.first << " " << ans.second << "\n";
	}
}