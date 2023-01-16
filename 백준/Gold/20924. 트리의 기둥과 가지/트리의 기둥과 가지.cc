#include <bits/stdc++.h>
using namespace std;
#define MAX 200010
vector<pair<int, int>> E[MAX];
int N, R;
int findPillar(int cur, int pre, int sum)
{
    if (E[cur].size() >= 3 || (cur == R && E[cur].size() >=2))
        return sum;

    for (int i = 0; i < E[cur].size(); i++)
    {
        int nx = E[cur][i].first;
        int nw = E[cur][i].second;
        if (pre == nx)
            continue;
        sum = findPillar(nx,cur,sum+nw);
    }    
    return sum;
}

int dfs(int cur, int pre, int sum)
{
    int mx = 0;
    if (E[cur].size() == 1 && cur != R)
    {
        return sum;
    }
    for (int i = 0; i < E[cur].size(); i++)
    {
        int nx = E[cur][i].first;
        int nw = E[cur][i].second;
        if (pre == nx)
            continue;
        mx = max(mx, dfs(nx, cur, sum + nw));
    }
    return mx;
}
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> R;
    for (int i = 0; i < N - 1; i++)
    {
        int node1, node2, weight;
        cin >> node1 >> node2 >> weight;
        E[node1].push_back({node2, weight});
        E[node2].push_back({node1, weight});
    }
    int tmp2 = findPillar(R, -1, 0);
    int tmp1 = dfs(R, -1, 0);
    cout << tmp2 << " " << tmp1 - tmp2;
}