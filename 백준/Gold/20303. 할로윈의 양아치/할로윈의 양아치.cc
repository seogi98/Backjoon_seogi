#include <bits/stdc++.h>
using namespace std;
#define MAX 40001
typedef long long ll;
int P[MAX];
int dp[MAX];
int unionFind(int cur)
{
    if(cur == P[cur])
    {
        return cur;
    }
    return P[cur] = unionFind(P[cur]);
}
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N,M,K;
    // 아이들이 가지고 있는 캔디
    int candy[MAX];
    // 친구 관계 수
    int friendCount[MAX];
    // union 캔디 수
    int candyCount[MAX];

    cin >> N >> M >> K;
    for(int i=1;i<=N;i++)
    {
        cin >> candy[i];
        P[i] = i;
        friendCount[i] = 1;
        candyCount[i] = candy[i];
    }
    for(int i=0;i<M;i++)
    {
        int node1 , node2;
        cin >> node1 >> node2;
        int node1P = unionFind(node1);
        int node2P = unionFind(node2);
        // 만약에 같지 않은 경우
        if(node1P != node2P)
        {
            // node1P 갯수를 늘려주고
            friendCount[node1P] += friendCount[node2P];
            candyCount[node1P] += candyCount[node2P];
            // node2P 초기화 해주고
            friendCount[node2P] =  0;
            candyCount[node2P] = 0;
            // 부모노드 바꿔준다.
            P[node2P] = node1P;
        }
    }
    // V size
    for(int i=1;i<=N;i++)
    {
        // 최대 친구수 
        for(int j=K;j>=1;j--)
        {
            if(friendCount[i] <= j)
            {
                dp[j] = max(dp[j],dp[j-friendCount[i]]+candyCount[i]);
            } 
        }
    }
    cout << dp[K-1];
}
