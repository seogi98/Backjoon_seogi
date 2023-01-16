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
    cin >> N >> M >> K;
    for(ll i=1;i<=N;i++)
    {
        cin >> A[i];
        update(i,A[i]);
    }
    for(ll i=0;i<M+K;i++)
    {
        ll Q;
        cin >> Q;
        if(Q==1)
        {
            ll node,change;
            cin >> node >> change;
            update(node,change-A[node]);
            A[node] = change;
            continue;
        }
        ll start,end;
        cin >> start >> end;
        cout << sum(end) - sum(start-1)<<"\n";
    }
}