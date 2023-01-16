#include <bits/stdc++.h>
using namespace std;
#define MAX 100001
struct Node
{
    int nx;
    int c = 0;
    int p = 0;
};
Node P[MAX];
int unionFind(int cur)
{
    if (P[cur].nx == cur)
    {
        return cur;
    }
    return P[cur].nx = unionFind(P[cur].nx);
}
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N, M, Q;
    cin >> N >> M >> Q;

    for (int i = 1; i <= N; i++)
    {
        int isC;
        cin >> isC;
        P[i].nx = i;
        isC == 1 ? P[i].c = 1 : P[i].p = 1;
    }
    for (int i = 0; i < M; i++)
    {
        int node1, node2;
        cin >> node1 >> node2;
        int node1P = unionFind(node1);
        int node2P = unionFind(node2);
        if (node1P != node2P)
        {
            P[node1P].nx = node2P;
            P[node2P].c += P[node1P].c;
            P[node2P].p += P[node1P].p;
            P[node1P].c = 0;
            P[node1P].p = 0;
        }
    }
    for (int i = 0; i < Q; i++)
    {
        int q;
        cin >> q;
        int qp = unionFind(q);
        P[qp].c > P[qp].p ? cout << "1\n" : cout << "0\n";
    }
}