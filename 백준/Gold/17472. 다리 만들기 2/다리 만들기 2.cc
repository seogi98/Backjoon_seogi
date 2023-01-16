#include <bits/stdc++.h>

#define MAX 10001
using namespace std;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};
int N, M;
int P[100];

priority_queue<pair<int,pair<int,int>>> pq;

void seeMap(int mp[11][11])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cout << mp[i][j] << " ";
        }
        cout << "\n";
    }
}

int find(int curNode)
{
    if(curNode == P[curNode])
    {
        return curNode;
    }
    return P[curNode] = find(P[curNode]);
}
int main()
{
    int ans = 0;
    //ios::sync_with_stdio(false);
    //cin.tie(NULL);
    //cout.tie(NULL);

    int mp[11][11];
    int vst[11][11];
    memset(vst, 0, sizeof(vst));
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> mp[i][j];
        }
    }
    //bfs 섬 구분
    int curNum = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (vst[i][j] != 0)
                continue;
            if (mp[i][j] == 0)
                continue;
            curNum++;
            queue<pair<int, int>> q;
            q.push({i, j});
            vst[i][j] = curNum;
            while (!q.empty())
            {
                int x = q.front().second;
                int y = q.front().first;
                q.pop();
                for (int k = 0; k < 4; k++)
                {
                    int tx = x + dx[k];
                    int ty = y + dy[k];
                    if (tx < 0 || tx >= M || ty < 0 || ty >= N)
                        continue;
                    if (vst[ty][tx] != 0)
                        continue;
                    if (mp[ty][tx] == 0)
                        continue;
                    vst[ty][tx] = curNum;
                    q.push({ty, tx});
                }
            }
        }
    }
    for(int i=1;i<=curNum;i++)
    {
        P[i] = i;
    }
    //seeMap(vst);
    //가로 다리 input
    for(int i=0;i<N;i++)
    {
        int node1=0;
        int node2=0;
        int preJ=0;
        int D=0;
        for(int j=0;j<M;j++)
        {
            if(vst[i][j]==0) continue;
            if(node1 == 0)
            {
                node1 = vst[i][j];
                preJ = j;
                continue;
            }
            D = j-preJ-1;
            preJ = j;
            node2 = node1;
            node1 = vst[i][j];
            if(D<=1) continue;
            if(node1 == node2) continue;
            pq.push({-D,{node1,node2}});
        }
    }
    //세로 다리 input
    for(int j=0;j<M;j++)
    {
        int node1=0;
        int node2=0;
        int D=0;
        int preI=0;
        for(int i=0;i<N;i++)
        {
            if(vst[i][j]==0) continue;
            if(node1 == 0)
            {
                node1 = vst[i][j];
                preI = i;
                continue;
            }
            D = i-preI-1;
            preI = i;
            node2 = node1;
            node1 = vst[i][j];
            if(D==1) continue;
            if(node1 == node2) continue;
            pq.push({-D,{node1,node2}});
        }
    }
    int result=0;
    while(!pq.empty())
    {
        int curD = -pq.top().first;
        int node1 = pq.top().second.first;
        int node2 = pq.top().second.second;
        int node1R = find(node1);
        int node2R = find(node2);
        pq.pop();
        if(node1R != node2R)
        {
            P[node1R] = node2R;
            result+=curD;
        }
    }
    int root = find(1);
    for(int i=2;i<=curNum;i++)
    {
        int tmp = find(i);
        if(root !=find(i))
        {
            result =-1;
        }
    }
    cout << result;
    
}