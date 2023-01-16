#include<bits/stdc++.h>
using namespace std;
#define MAX 50
typedef long long ll;
// 구간을 절반으로 나눈 구간.
ll middle;
ll N,S;
// 부분집합의 합, 개수
map<ll,ll> cntL;
map<ll,ll> cntR;

// 물건
vector<ll> V(MAX,0);

ll answer=0;

// 처음 - 중간까지 dfs 
void dfsL(ll idx, ll sum)
{
    if(idx == middle)
    {
        cntL[sum]++;
        return;
    }
    dfsL(idx+1,sum+V[idx]);
    dfsL(idx+1,sum);
}

// 중간 - 마지막 dfs
void dfsR(ll idx,ll sum)
{
    if(idx==N)
    {
        cntR[sum]++;
        return;
    }
    dfsR(idx+1,sum);
    dfsR(idx+1,sum+V[idx]);
}
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    cin >> S;
    middle = N/2;
    for(ll i=0;i<N;i++)
    {
        cin >> V[i];
    }
    dfsL(0,0);
    dfsR(middle,0);
    for(auto i : cntL)
    {
        answer+=cntR[S-i.first]*i.second;
    }
    if(S == 0)
        answer --;
    cout << answer;
}