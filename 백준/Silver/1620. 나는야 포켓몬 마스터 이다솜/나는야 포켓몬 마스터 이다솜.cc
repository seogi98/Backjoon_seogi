#include <bits/stdc++.h>
using namespace std;
#define MAX 700000
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N,M;
    cin >> N >> M;
    map<string,string> ans;
    for(int i=1;i<=N;i++)
    {
        string t;
        cin >> t;
        ans[t] = to_string(i);
        ans[to_string(i)] = t;
    } 
    for(int i=0;i<M;i++)
    {
        string A;
        cin >> A;
        cout << ans[A] << "\n";
    }    
}