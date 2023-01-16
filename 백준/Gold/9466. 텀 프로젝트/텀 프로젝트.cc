#include <bits/stdc++.h>
using namespace std;
#define MAX 200010
#define INF 299999
typedef long long ll;
//그래프 이론에서 단순 경로는 처음 정점과 끝 정점을 제외하고 중복된 정점이 없는 경로를 말한다.
vector<int> E[MAX];
// 역방향 간선
vector<int> rv[MAX];
int P[MAX];
bool isCy[MAX];
bool vst[MAX];
vector<int> vstS;
int unionFind(int cur)
{
    if (cur == P[cur])
    {
        return cur;
    }
    return P[cur] = unionFind(P[cur]);
}
// 역방향 간선을 타고가면서 나오는 노드 => 자기자신으로 돌아올 경우 cycle
void dfs(int cur, int pre, int start)
{
    for(int i=0;i<rv[cur].size();i++)
    {
         int nx = rv[cur][i];
        //시작지점으로 돌아올 경우
        if(nx == start)
        {
            for(int j=0;j<vstS.size();j++)
            {
                isCy[vstS[j]] = true;
            }
            continue;
        }
        if(nx == pre) continue;
        vstS.push_back(nx);
        dfs(nx,cur,start);
        vstS.pop_back();
    }
}
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    while (T--)
    {
        int N;
        int ans = 0;
        cin >> N;
        for (int i = 1; i <= N; i++)
        {
            P[i] = i;
            isCy[i] = false;
            E[i].clear();
            rv[i].clear();
            vstS.clear();
            vst[i] = 0;
        }
        vector<int> startV;
        // 사이클 시작노드 탐색
        for (int i = 1; i <= N; i++)
        {
            int node1 = i;
            int node2;
            cin >> node2;
            E[node1].push_back(node2);
            rv[node2].push_back(node1);
            int node1P = unionFind(node1);
            int node2P = unionFind(node2);
            if (node1P != node2P)
            {
                P[node1P] = node2P;
                continue;
            }
            if (node1P == node2P)
                startV.push_back(node2);
        }
        for (int j = 0; j < startV.size(); j++)
        {
            int start = startV[j];
            // 사이클 탐색
            for (int i = 0; i < E[start].size(); i++)
            {
                if(isCy[start]) continue;
                vstS.push_back(start);
                dfs(start,0,start);
                vstS.pop_back();
            }
        }
        for (int i = 1; i <= N; i++)
        {
            if (!isCy[i])
                ans++;
        }
        cout << ans << "\n";
    }
}