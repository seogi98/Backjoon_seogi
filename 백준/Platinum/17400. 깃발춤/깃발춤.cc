#include <bits/stdc++.h>
using namespace std;
#define MAX 5000000
#define INF 2000000
typedef long long ll;
//깃발을 왼쪽으로 흔들고, 거리가 홀수인 공연자는 오른쪽으로 흔든다
// 짝수 + 홀수 -
ll N,Q;
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
    cin >> N >> Q;
    for(ll i=1;i<=N;i++)
    {
        cin >> A[i];
		//홀수일경우 음수
		if(i%2) A[i] = -A[i];
        update(i,A[i]);
    }
    for(ll i=0;i<Q;i++)
    {
        ll q;
        cin >> q;
		// 1일경우 구간 find
        if(q==1)
		{
			int node1 , node2;
			cin >> node1 >> node2;
			cout << abs(sum(node2) - sum(node1-1))<<"\n";	
			continue;		
		}
		// 2일경우 카리스마 더해줌
		int node , weight;
		cin >> node >> weight;
		// 홀수일 경우 weight 음수
		if(node%2) weight = -weight;
		update(node,weight);
		A[node] += weight;
    }
}