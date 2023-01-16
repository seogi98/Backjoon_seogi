#include <bits/stdc++.h>
using namespace std;
#define MAX 1010
#define INF 2147483646
// 트리 DP문제
// 도착지인 정점 2에서 다익스트라를 통해 거리를 구한다.
// 결론적으로 멀어지거나 가까워지거나 하나이기떄문에 방향성이 정해진다.
// 따라서 root부터 트리 생성
// 1에서 부터 시작해서 dp[1] = 1 인접하고 이동할 수 있는 node에 대해서
// node[next] += dp[pre]
// rec(next);
// answer = dp[2]
vector<pair<int, int>> E[MAX];
int dst[MAX];
int dp[MAX];
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N, M;
    //정점, 간선
    cin >> N >> M;
    //insert
    for (int i = 0; i < M; i++)
    {
        int node1, node2, weight;
        cin >> node1 >> node2 >> weight;
        E[node1].push_back({node2, weight});
        E[node2].push_back({node1, weight});
    }
    //다익스트라 start
    for (int i = 0; i <= N; i++)
    {
        dst[i] = INF;
    }
    priority_queue<pair<int, int>> pq; // weight,cur;
    pq.push({0, 2});                   // 2에서 부터 시작
    dst[2] = 0;
    dp[2] = 1;
    while (!pq.empty())
    {
        int curW = -pq.top().first;
        int cur = pq.top().second;
        pq.pop();
        if (curW > dst[cur])
            continue;
        for (int i = 0; i < E[cur].size(); i++)
        {
            int nx = E[cur][i].first;
            int nxdist = E[cur][i].second + curW;
            if (dst[nx] > nxdist)
            {
                dst[nx] = nxdist;
                pq.push({-nxdist, nx});
            }
            if(dst[cur] < dst[nx])
            {
                dp[nx] += dp[cur];
            }
        }
    }
    cout << dp[1];
}