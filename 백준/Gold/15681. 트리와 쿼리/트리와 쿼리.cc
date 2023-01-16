#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <queue>
#include <string.h>
#include <vector>
#include <math.h>
#include <map>

#define MAX 100001
using namespace std;
int dp[MAX];

vector<int> E[MAX];
bool vst[MAX];
int countSubtreeNodes(int curNode)
{
    vst[curNode] = true;
    dp[curNode] = 1;
    //cout << "curnode :" << curNode << "\n";
    for (int i = 0; i < E[curNode].size(); i++)
    {
        if (!vst[E[curNode][i]])
        {
            dp[curNode] += countSubtreeNodes(E[curNode][i]);
        }
    }
    return dp[curNode];
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, R, Q;
    cin >> N >> R >> Q; //(정점 , 루트, 쿼리)
    for (int i = 0; i < N - 1; i++)
    {
        int A, B;
        cin >> A >> B;
        E[A].push_back(B);
        E[B].push_back(A);
    }
    memset(dp, 0, sizeof(dp));
    memset(vst, false, sizeof(vst));
    countSubtreeNodes(R);
    for (int i = 0; i < Q; i++)
    {
        int U;
        cin >> U;
        cout << dp[U] << "\n";
    }
}
