#include <iostream>
#include <algorithm>
#include <string>
#include <stdio.h>
#include <queue>
#include <string.h>
#include <vector>
#include <math.h>
#include <stack>

//dp[i] == dp[i-1] continue;
//dp[i] = dp[i-1]+1;

#define MAX 1000001
using namespace std;
vector<pair<pair<int,int>,int>> V;
bool cmp1(pair<pair<int,int>,int> p1,pair<pair<int,int>,int>p2)
{
    return p1.first.first < p2.first.first;
}
bool cmp2(pair<pair<int,int>,int> p1,pair<pair<int,int>,int> p2)
{
    return p1.first.second < p2.first.second;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int T;
        cin >> T;
        V.push_back({{T,i},0});
    }
    sort(V.begin(),V.end(),cmp1);
    V[0].second=0;
    for(int i=1;i<N;i++)
    {
        if(V[i].first.first==V[i-1].first.first)
        {
            V[i].second = V[i-1].second;
            continue;
        }
        V[i].second = V[i-1].second+1;
    }
    sort(V.begin(),V.end(),cmp2);
    for(int i=0;i<N;i++)
    {
        cout << V[i].second << " ";
    }
    
}