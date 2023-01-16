#include <bits/stdc++.h>
using namespace std;
#define MAX 200010
#define INF 299999
typedef long long ll;
//그래프 이론에서 단순 경로는 처음 정점과 끝 정점을 제외하고 중복된 정점이 없는 경로를 말한다.
vector<int> E[MAX];
int P[MAX];
int cycleP[MAX];
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
void dfs(int cur, int start, int pre)
{
    vst[cur] = true;
    for (int i = 0; i < E[cur].size(); i++)
    {
        int nx = E[cur][i];
        if (start == nx && start != pre)
        {
            vstS.push_back(nx);
            for (int j = 0; j < vstS.size(); j++)
            {
                isCy[vstS[j]] = true;
                cycleP[vstS[j]] = vstS[j];
            }
            return;
        }
        if (start == nx && start == pre)
            continue;
        if (vst[nx])
            continue;
        vstS.push_back(nx);
        dfs(nx, start, cur);
        vstS.pop_back();
    }
}

//사이클 에서 아래로 내려가게 되면 그 요소들은 사이클을 root로 가지는 tree가 생성된다.
void dfsRootCycle(int cur, int pre, int start)
{
    cycleP[cur] = start;
    for (int i = 0; i < E[cur].size(); i++)
    {
        int nx = E[cur][i];
        if (nx == pre)
            continue;
        dfsRootCycle(nx, cur, start);
    }
}
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    int Q;
    int ans = 0;
    cin >> N >> Q;
    for (int i = 1; i <= N; i++)
    {
        P[i] = i;
    }
    int start = 0;
    for (int i = 0; i < N; i++)
    {
        int node1, node2;
        cin >> node1 >> node2;
        E[node1].push_back(node2);
        E[node2].push_back(node1);
        int node1P = unionFind(node1);
        int node2P = unionFind(node2);
        if (node1P != node2P){
            P[node1P] = node2P;
            continue;
        }
        if (node1P == node2P)
            start = node1;
    }
    for (int i = 0; i < E[start].size(); i++)
    {
        if(vst[E[start][i]]) continue;
        vstS.clear();
        vstS.push_back(E[start][i]);
        dfs(E[start][i], start, start);
    }
    for (int i = 1; i <= N; i++)
    {
        if (isCy[i])
        {
            for (int j = 0; j < E[i].size(); j++)
            {
                //다음 노드
                int nx = E[i][j];
                if (isCy[nx])
                    continue;
                dfsRootCycle(nx, i, i);
            }
        }
    }
    for (int i = 0; i < Q; i++)
    {
        int node1, node2;
        cin >> node1 >> node2;
        ans = 1;
        if (cycleP[node1] != cycleP[node2])
        {
            ans = 2;
        }
        cout << ans << "\n";
    }
}
