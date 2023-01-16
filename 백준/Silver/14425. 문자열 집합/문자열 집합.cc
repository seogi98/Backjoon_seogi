#include <bits/stdc++.h>
using namespace std;
map<string, bool> mp;
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N, M;
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        string tmp;
        cin >> tmp;
        mp[tmp] = true;
    }
    int ans=0;
    for(int j=0;j<M;j++)
    {
        string tmp;
        cin >> tmp;
        if(mp[tmp]) ans++;
    }
    cout << ans;
}