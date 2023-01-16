#include <bits/stdc++.h>
using namespace std;
#define MAX 300
vector<int> E[MAX];
bool vst[MAX];
int result[MAX][MAX];
int N;
void dfs(int curNode,int start)
{
    vst[curNode] = true;
    for(int i=0;i<E[curNode].size();i++)
    {
        int nextNode = E[curNode][i];
        result[start][nextNode] = true;
        if(vst[nextNode]) continue;
        dfs(nextNode,start);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            int T;
            cin >> T;
            if(T)
            {
                E[i].push_back(j);
            }
        }
    }
    for(int i=1;i<=N;i++)
    {
        memset(vst,false,sizeof(vst));
        dfs(i,i);
    }
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=N;j++)
        {
            cout << result[i][j] <<" ";
        }
        cout << "\n";
    }
}
