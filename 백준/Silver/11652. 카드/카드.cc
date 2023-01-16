#include<bits/stdc++.h>
using namespace std;
map<long long,int> M;
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    for(int i=0;i<N;i++)
    {
        long long T;
        cin >> T;
        M[T]++;
    }
    int mx=0;
    long long ans;
    for(auto i : M)
    {
        if(mx<i.second)
        {
            mx = i.second;
            ans = i.first;
        }
    }
    cout << ans;
}    
    