#include <bits/stdc++.h>
using namespace std;
#define MAX 5000000
#define INF 2000000
typedef long long ll;
ll N,M,K;
vector<ll> tree(MAX);
vector<ll> A(MAX);
ll sum(ll i)
{
    ll ans = 0;
    while(i>0)
    {
        ans +=tree[i];
        //끝에 노드 지우기
        i -= (i&-i);
    }
    return ans;
}
void update(ll i,ll diff)
{
    while(i<tree.size())
    {
        tree[i] += diff;
        i +=(i&-i);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	ll N,Q;
	cin >> N >> Q;
    for(ll i=1;i<=N;i++)
    {
        cin >> A[i];
        update(i,A[i]);
    }
	for(ll i=0;i<Q;i++)
	{
		ll x,y,a,b;
		cin >> x >> y >> a >> b;
		
		ll out = sum(max(y,x)) - sum(min(x,y)-1);
		cout << out << "\n";
		update(a,b-A[a]);
		A[a] = b;
	}
	
}