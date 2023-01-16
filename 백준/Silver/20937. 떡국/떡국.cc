#include<bits/stdc++.h>
using namespace std;
#define MAX 100000
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    map<int,int> mp;
    int mx = 0;
    for(int i=0;i<N;i++)
    {
        int t;
        cin >> t;
        mp[t]++;
        mx = max(mx,mp[t]);
    }   
    cout << mx;
}