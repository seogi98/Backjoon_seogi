#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
#define MAX 18446744073709551616
ll ans=0;
void dfs(ll cur,ll key,ll mk,ll idx)
{
	if(idx>64) return;
	if(cur == key)
	{
		ans = mk;
		return;
	}
	dfs(cur*2,key,mk,idx+1);
	if(mk!=0) return;
	dfs(cur*2-1,key,idx,idx+1);
}
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	ll N;
	cin >> N;
	dfs(1,N,0,0);
	cout << ans+1;
}