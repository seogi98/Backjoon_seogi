#include<bits/stdc++.h>
using namespace std;
#define MAX 10000
#define INF 200000000000
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    long long N,M;
    cin >> N >> M;
    vector<pair<long long,long long>> E[MAX];
    // 울프
    long long dstW[MAX][2];
    // 여우
    long long dstF[MAX];
    for(int i=1;i<=N;i++)
    {
        dstW[i][0] = INF;
        dstW[i][1] = INF;
        dstF[i] = INF;
    }
    for(long long i=1;i<=M;i++)
    {
        long long node1 , node2 , w;
        cin >> node1 >> node2 >> w;
        E[node1].push_back({node2,w*2});
        E[node2].push_back({node1,w*2});
    }
    // 여우 {dst node}
    priority_queue<pair<long long,long long>> pqF;
    pqF.push({0,1});
    dstF[1] = 0;
    while(!pqF.empty())
    {
        long long curWeight = -pqF.top().first;
        long long cur = pqF.top().second;
        pqF.pop();
        if(dstF[cur] < curWeight) continue;
        for(long long i=0;i<E[cur].size();i++)
        {
            long long nx = E[cur][i].first;
            long long nxWeight = curWeight + E[cur][i].second;
            if(nxWeight >= dstF[nx]) continue;
            dstF[nx] = nxWeight;
            pqF.push({-nxWeight,nx});
        }
    }
    // 늑대 {dst node 빠르기}
    priority_queue<pair<long long,pair<long long,bool>>> pqW;
    pqW.push({0,{1,true}});
    dstW[1][true] = 0;
    while(!pqW.empty())
    {
        long long curWeight = -pqW.top().first;
        long long cur = pqW.top().second.first;
        bool isFast = pqW.top().second.second;
        pqW.pop();
        if(dstW[cur][isFast] < curWeight) continue;
        for(long long i=0;i<E[cur].size();i++)
        {
            long long nx = E[cur][i].first;
            long long nxWeight = isFast?E[cur][i].second/2:E[cur][i].second*2;
            nxWeight+=curWeight;
            if(nxWeight >= dstW[nx][!isFast]) continue;
            dstW[nx][!isFast] = nxWeight;
            pqW.push({-nxWeight,{nx,!isFast}});
        }
    }
    long long ans=0;
    for(long long i=1;i<=N;i++)
    {
        if(min(dstW[i][0],dstW[i][1]) > dstF[i]) ans++;
    }
    cout << ans;
    
}