#include <bits/stdc++.h>
using namespace std;
#define MAX 100010
#define DIV 1000000007
long long dp[MAX][8];
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    long long N, M;
    cin >> N >> M;
    vector<long long> E[MAX];
    set<long long> node;
    for (long long i = 0; i < M; i++)
    {
        long long node1, node2;
        cin >> node1 >> node2;
        node.insert(node1);
        node.insert(node2);
        E[node1].push_back(node2);
        E[node2].push_back(node1);
    } 
    for(long long i=1;i<=8;i++)
    {
        for(auto j : node)
        {
            long long cur = j;
            if(i == 1)
            {
                dp[cur][i] = 1;
                continue;
            }
            for(long long k=0;k<E[cur].size();k++)
            {
                long long nx = E[cur][k];
                dp[j][i] += dp[nx][i-1];
                dp[j][i] %= DIV;
            }
        }
    }
    long long ans=0;
    for(auto i : node)
    {
        ans+=dp[i][8];
        ans%=DIV;
    }
    cout << ans%DIV;
}