#include <bits/stdc++.h>
using namespace std;
#define MAX 101
#define INF 1987654321
typedef long long ll;
int cabin[MAX];
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int dst[MAX][MAX];
    int N,M;
    cin >> N >> M;
    vector<int> E[MAX];
    for(int i=0;i<M;i++)
    {
        int node1 , node2;
        cin >> node1 >> node2;
        E[node1].push_back(node2);
        E[node2].push_back(node1);
    }
    for(int i=1;i<=N;i++)
    {
        int start = i;
        bool vst[MAX];
        memset(vst,false,sizeof(vst));
        vst[start] = true;
        queue<pair<int,int>> q;
        q.push({start,0});
        while(!q.empty())
        {
            int cur = q.front().first;
            int curw = q.front().second;
            q.pop();
            for(int j=0;j<E[cur].size();j++)
            {
                int nx = E[cur][j];
                if(vst[nx]) continue;
                vst[nx] = true;
                cabin[i]+=(curw+1);
                q.push({nx,curw+1});
            }
        }
    }
    int answer=INF;
    int ans=0;
    for(int i=1;i<=N;i++)
    {
        if(answer > cabin[i])
        {
            answer = cabin[i];
            ans = i;
        }
    }
    cout << ans;

}


