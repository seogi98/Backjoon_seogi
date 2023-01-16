#include <bits/stdc++.h>
using namespace std;
#define MAX 300010
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    while (T--)
    {
        int N, M;
        cin >> N >> M;
        vector<int> E[MAX];
        for (int i = 0; i < M; i++)
        {
            int node1, node2;
            cin >> node1 >> node2;
            E[node1].push_back(node2);
            E[node2].push_back(node1);
        }
        int vst[MAX];
        memset(vst, 0, sizeof(vst));
        queue<pair<int, int>> q;
        string ans = "YES";
        for (int i = 1; i <= N; i++)
        {
            int start = i;
            if(vst[start]!=0) continue;
            q.push({start, 1});
            vst[start] = 1;
            while (!q.empty())
            {
                int cur = q.front().first;
                int team = q.front().second;
                q.pop();
                for (int i = 0; i < E[cur].size(); i++)
                {
                    int nx = E[cur][i];
                    int nxT = team == 1 ? 2 : 1;
                    if (vst[nx] == 0)
                    {
                        vst[nx] = nxT;
                        q.push({nx, nxT});
                        continue;
                    }
                    if (vst[nx] != nxT)
                    {
                        ans = "NO";
                        break;
                    }
                }
            }
        }
        cout << ans << '\n';
    }
}