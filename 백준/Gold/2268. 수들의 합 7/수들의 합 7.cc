#include <bits/stdc++.h>
using namespace std;
#define MAX 9000000
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
	for(ll i=0;i<Q;i++)
	{
		ll oper,node1,node2;
		cin >> oper >> node1 >> node2;
		if(oper == 0)
		{
			cout << sum(max(node2,node1))-sum(min(node1,node2)-1) <<"\n";
		}
		if(oper == 1)
		{
			update(node1,node2-A[node1]);
			A[node1] = node2;
		}
	}
}