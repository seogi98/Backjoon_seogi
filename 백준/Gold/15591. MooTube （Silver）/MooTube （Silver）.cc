#include <bits/stdc++.h>
using namespace std;
#define MAX 6000
#define INF 1987654321
typedef long long ll;
vector<pair<int,int>> E[MAX];
int vst[MAX];
int dst[MAX][MAX];

void dfs(int cur, int mn,int pre,int start)
{
    dst[start][cur] = mn;
    for(int i=0;i<E[cur].size();i++)
    {
        int mmn = min(E[cur][i].second,mn);
        int nx = E[cur][i].first;
        if(nx == pre) continue;
        dfs(nx,mmn,cur,start);
    }
}
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N,Q;
    cin >> N >> Q;    
    for(int i=1;i<N;i++)
    {
        int node1, node2, weight;
        cin >> node1 >> node2 >> weight;
        E[node1].push_back({node2,weight});
        E[node2].push_back({node1,weight});
    }
    for(int i=1;i<=N;i++)
    {
        dfs(i,INF,0,i);
    }
    // 탐색
    for(int i=0;i<Q;i++)
    {
        int k,v;
        cin >> k >> v;
        int ans =0;
        for(int j=1;j<=N;j++)
        {
            if(v==j) continue;
            if(dst[v][j]>=k)
            {
                ans++;
            }
        }
        cout << ans << "\n";
        
    }
}


