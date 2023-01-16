#include <bits/stdc++.h>
using namespace std;
#define MAX 5000000
// 다 칠하고 그위에 덮음
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	string str;
	cin >> N >> str;
	int b=0,r=0;
	char pre = str[0];
	char cur = pre;
	int ans=0;
	for(int i=1;i<N;i++)
	{
		cur = str[i];
		if(pre == cur) continue;
		pre == 'B'?b++:r++;
		pre = cur;
	}
	cur == 'B'?b++:r++;
	ans = min(b,r)+1;
	cout << ans;
}