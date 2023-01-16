#include <bits/stdc++.h>
using namespace std;
#define MAX 500010
#define INF 1987654321
// Left =  sum*2+base+1;
// sum = sum+cur;
// right = sum*2+base;
vector<int> T[MAX];
vector<int> E[MAX];
int nodeN[MAX];
int pt[MAX];
pair<int, int> dt[MAX];
int findN(int cur)
{
    int sum = 1;
    for (int i = 0; i < T[cur].size(); i++)
    {
        int next = T[cur][i];
        sum += findN(next);
    }
    nodeN[cur] = sum;
    return sum;
}
void dupT(int cur, int base)
{
    int sum = 0;
    for (int i = 0; i < T[cur].size(); i++)
    {
        int next = T[cur][i];
        dt[next].first = sum * 2 + base + 1;
        sum = sum + nodeN[next];
        dt[next].second = sum * 2 + base;
        dupT(next, dt[next].first);
    }
}
void init(int cur)
{
    pt[cur] = true;
    for(int i=0;i<E[cur].size();i++)
    {
        int next = E[cur][i];
        if(pt[next]) continue;
        T[cur].push_back(next);
        init(next);
    }
    if(T[cur].empty())return;
    sort(T[cur].begin(),T[cur].end());
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int P;
        cin >> P;
        while (1)
        {
            int C;
            cin >> C;
            if (C == -1)
                break;
            E[P].push_back(C);      
            E[C].push_back(P);
        }
    }
    int root;
    cin >> root;
    memset(nodeN, 0, sizeof(nodeN));
    memset(pt,false,sizeof(pt));
    init(root);
    findN(root);
    dt[root] = {1,2*N};
    dupT(root, 1);
    for (int i = 1; i <= N; i++)
    {
        cout << i << " " << dt[i].first << " " << dt[i].second << "\n";
    }
}
