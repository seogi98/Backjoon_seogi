#include <bits/stdc++.h>
using namespace std;
#define MAX 2010
#define INF 2999999998000
typedef long long ll;
struct CUR
{
    // 이동 거리
    ll dst;
    // 현제 노드
    ll cur;
    //마법 쓴 횟수
    ll magicN;
};
struct compare
{
    bool operator()(CUR C1, CUR C2)
    {
        return C1.dst > C2.dst;
    }
};

// [i번 간선][마법을 쓴 횟수]
ll origin[MAX * 2][110];

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll N, M, A, B;
    cin >> N >> M >> A >> B;
    vector<pair<ll, ll>> E[MAX];
    // [방문한 노드][마법을 쓴 횟수]
    ll dst[MAX][101];
    for (ll i = 1; i <= M; i++)
    {
        ll node1, node2, W;
        cin >> node1 >> node2 >> W;
        origin[i][0] = W;
        E[node1].push_back({node2, i});
        E[node2].push_back({node1, i});
    }
    ll K;
    cin >> K;
    // 마법 썻을때 저장
    for (ll i = 1; i <= K; i++)
    {
        for (ll j = 1; j <= M; j++)
        {
            cin >> origin[j][i];
        }
    }
    for (ll i = 0; i <= N; i++)
    {
        for (ll j = 0; j <= K; j++)
        {
            dst[i][j] = INF;
        }
    }
	dst[A][0] = 0;
    priority_queue<CUR, vector<CUR>, compare> pq;
    pq.push({0, A, 0});
    while (!pq.empty())
    {
        // 현제 노드
        ll cur = pq.top().cur;
        // 이동 거리
        ll curD = pq.top().dst;
        // 마법 쓴 횟수
        ll curM = pq.top().magicN;
        pq.pop();
		
        if (dst[cur][curM] < curD)
            continue;
        // 인접 노드 이동 : 마법 안쓰고 이동
        for (ll i = 0; i < E[cur].size(); i++)
        {
            ll nx = E[cur][i].first;
            ll nxM = curM;
            ll nxD = curD + origin[E[cur][i].second][nxM];
            if (dst[nx][nxM] <= nxD)
                continue;
            dst[nx][nxM] = nxD;
            pq.push({nxD, nx, nxM});
        }
        // 마법 더 못쓰면 걸러낸다.
        if(curM >= K) continue;
        // 인접 노드 이동 : 마법 쓰고 이동
        for (ll i = 0; i < E[cur].size(); i++)
        {
            ll nx = E[cur][i].first;
            ll nxM = curM + 1;
            ll nxD = curD + origin[E[cur][i].second][nxM];
            if (dst[nx][nxM] <= nxD)
                continue;
            dst[nx][nxM] = nxD;
            pq.push({nxD, nx, nxM});
        }
    }
    ll answer=dst[B][0];
    for(int i=1;i<=K;i++)
    {
        if(dst[B][i] == INF) continue;
        answer = min(dst[B][i],answer);
    }
    cout << answer;
}


