#include <bits/stdc++.h>
using namespace std;
#define MAX 10100
#define INF 1987654321
int P[MAX];
int unionFind(int cur)
{
    if (P[cur] == cur)
    {
        return cur;
    }
    return P[cur] = unionFind(P[cur]);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N, M, K;
    cin >> N >> M >> K;
    vector<int> A(MAX, 0);
    vector<int> mnCost(MAX, 0);
    vector<int> friendCount(MAX, 0);
    for (int i = 1; i <= N; i++)
    {
        cin >> A[i];
        mnCost[i] = A[i];
        friendCount[i] = 1;
        P[i] = i;
    }
    for (int i = 0; i < M; i++)
    {
        int node1, node2;
        cin >> node1 >> node2;
        int node1P = unionFind(node1);
        int node2P = unionFind(node2);
        // 만약에 다를경우
        if (node1P != node2P)
        {
            //최소값갱신
            mnCost[node1P] = min(mnCost[node2P], mnCost[node1P]);
            mnCost[node2P] = INF;
            friendCount[node1P] +=friendCount[node2P];
            friendCount[node2P] = 0;
            //node change
            P[node2P] = node1P;
            continue;
        }
        // 같을경우 최소값 갱신
        mnCost[node1P] = min(mnCost[node1P],A[i]);
    }
    int ans=0;
    int count=0;
    for(int i=1;i<=N;i++)
    {
        if(mnCost[i] == INF) continue;
        ans +=mnCost[i];
        count +=friendCount[i];
    }
    if(count != N || ans >K) {
        cout << "Oh no";
        return 0;
    }
    cout << ans;
}
