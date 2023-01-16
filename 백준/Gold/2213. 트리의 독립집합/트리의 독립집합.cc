#include<bits/stdc++.h>
#define MAX 10010
using namespace std;
int dp[MAX][2]; // first : 포함하려는 노드 second 1 == 포함 0 == 미포함

vector<int> E[MAX];
int arr[MAX];
bool vst[MAX];
vector<int> V;
int N;
void dfs(int curNode, int num)
{
    if (num > N+1)
    {
        return;
    }
    vst[curNode]=true;
    dp[curNode][1] = arr[curNode];
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
    return;
}
// back tracking
void ffind(int cur,bool check,int parent) // 현제 노드 , 이전 노드가 check되어 있는지 확인
{
    //만약에 전에 노드가 포함되어있지않고 dp[1]이 더 큰 경우 포함된다.
    if(!check && (dp[cur][1] > dp[cur][0]))
    {
        V.push_back(cur);
        //check
        check = true;
    }
    //아니면 포함하지 않음
    else
    {
        check = false;
    }
    for(int i=0;i<E[cur].size();i++)
    {
        int nx = E[cur][i];
        if(nx == parent) continue;
        if(vst[nx]) continue;
        vst[nx] = true;
        ffind(nx,check,cur);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> arr[i];
    }
    while (cin.eof() == false)
    {
        int node1, node2;
        cin >> node1 >> node2;
        E[node1].push_back(node2);
        E[node2].push_back(node1);
    }
    int root[2];
    memset(vst,false,sizeof(vst));
    dfs(1, 1);
    cout << max(dp[1][0],dp[1][1])<<"\n";
    memset(vst,false,sizeof(vst));
    ffind(1,false,-1);
    sort(V.begin(),V.end());
	//오름 차순
	for(int i=0;i<V.size();i++)
	{
		cout << V[i] << " ";
	}

}