#include<bits/stdc++.h>
using namespace std;
#define MAX 100
typedef long long ll;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	ll N,K;
	string ans="-1";
	cin >> N >> K;
	for(ll i=1;i<=N;i++)
	{
		string tmp = to_string(i);
		ll len = tmp.size();
		if(K-len <= 0){
			ans = tmp[(K-1)];
			break;
		}
		K -=len;
	}
	cout << ans;

}