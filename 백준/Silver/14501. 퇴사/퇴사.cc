#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;


int N;

vector<pair<int,int>> v; // day , cost 
priority_queue<int,vector<int>,less<int>> pq;

void dfs(int n,int result)
{
    if(n>=N)
    {
        pq.push(result);
        return;
    }
    if(n+v[n].first<=N)
    {
        dfs(n+v[n].first,result+v[n].second);
    }
    dfs(n+1,result);
}
int main(void)
{
    int D,C;
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;
    for(int i=0;i<N;i++)
    {
        cin >>  D >> C;
        v.push_back({D,C});
    }
    dfs(0,0);
    if(!pq.empty()) cout << pq.top();

}