#include<bits/stdc++.h>
using namespace std;
#define MAX 200000

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int warm,moist;
	cin >> warm >> moist;
	int ans  =0;
	int mn = min(warm,moist);
	int mx = max(warm,moist);
	ans = mx+mn+(mn/10);
	cout << ans;
}