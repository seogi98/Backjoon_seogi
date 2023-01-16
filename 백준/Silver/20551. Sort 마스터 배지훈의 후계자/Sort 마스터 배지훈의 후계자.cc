#include <bits/stdc++.h>
using namespace std;
#define MAX 101
#define INF 1987654321
map<int,int> ans;
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N,M;
    cin >> N >> M;
    vector<int> in;
    for(int i=0;i<N;i++)
    {
        int t;
        cin >> t;
        in.push_back(t);
    }
    sort(in.begin(),in.end());
    for(int i=0;i<N;i++)
    {
        if(ans.count(in[i])) continue;
        ans[in[i]] = i;
    }
    for(int i=0;i<M;i++)
    {
        int D;
        int result=-1;
        cin >> D;
        if(ans.count(D)) result = ans[D];
        cout << result << "\n";
    }
}



