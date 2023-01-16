#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <queue>
#include <string.h>
#include <vector>
#include <math.h>
#include <map>
#include<stack>

#define MAX 1000001
using namespace std;
int dp[MAX][2]; // first : 포함하려는 노드 second 1 == 포함 0 == 미포함

vector<int> E[MAX];
int arr[MAX];
bool vst[MAX];
int N;
void dfs(int curNode, int num)
{
    if (num > N+1)
    {
        return ;
    }
    vst[curNode]=true;
    dp[curNode][1] = 1;
    dp[curNode][0] = 0;    
    for(int i=0;i<E[curNode].size();i++)
    {
        int nextNode = E[curNode][i];
        if(nextNode == curNode){continue;}
        if(!vst[nextNode])
        {
            dfs(nextNode,num+1);
            dp[curNode][0] += max(dp[nextNode][1],dp[nextNode][0]);//현제노드 미포함 
            dp[curNode][1] += dp[nextNode][0]; 
        }
    }
    return ;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    for(int i=0;i<N-1;i++)
    {
        int node1, node2;
        cin >> node1 >> node2;
        E[node1].push_back(node2);
        E[node2].push_back(node1);
    }
    int root[2];
    memset(vst,false,sizeof(vst));
    dfs(1, 1);
    cout << N-max(dp[1][0],dp[1][1]);
}