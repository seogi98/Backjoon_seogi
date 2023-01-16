#include <bits/stdc++.h>
using namespace std;
#define MAX 500010
#define INF 200000000000
typedef long long ll;
ll tree[MAX]; // min , max
ll A[MAX];
void init(ll node, ll start, ll end)
{
    if (start == end)
    {
        tree[node] = A[start];
        return;
    }
    tree[node] = 0;
    init(node * 2, start, (start + end) / 2);
    init(node * 2 + 1, (start + end) / 2 + 1, end);
}
ll findq(ll node, ll start, ll end, ll F,ll result)
{
    if (F < start || end < F)
    {
        return INF;
    }
    result +=tree[node];
    if (start == end)
    {
        return result;
    }
    ll L = findq(node * 2, start, (start + end) / 2, F,result);
    ll R = findq(node * 2 + 1, (start + end) / 2 + 1, end, F,result);
    if(L==INF) return R;
    if(R==INF) return L;
    return result;
}
void update(ll node, ll start, ll end, ll left, ll right, ll key)
{
    if (left <= start && end <= right)
    {
        tree[node] += key;
        return;
    }
    if (right < start || left > end)
    {
        return;
    }
    update(node * 2, start, (start + end) / 2, left, right, key);
    update(node * 2 + 1, (start + end) / 2 + 1, end, left, right, key);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll N;
    cin >> N;
    for (ll i = 1; i <=N; i++)
    {
        cin >> A[i];
    }
    init(1,1,N);
    ll M;
    cin >> M;
   for(ll i=0;i<M;i++)
    {
        ll q;
        cin >> q;
        if(q==1)
        {
            ll left,right,key;
            cin >> left >> right >> key;
            update(1,1,N,left,right,key);
            continue;
        }
        ll F;
        cin >> F;
        cout << findq(1,1,N,F,0)<<"\n";
    }
}