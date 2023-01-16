#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll N;
    cin >> N;
    vector<ll> arr;
    for(ll i=0;i<N;i++)
    {
        ll t;
        cin >> t;
        arr.push_back(t);
    }
    sort(arr.begin(),arr.end());
    ll mx = 0;
    ll start = 0;
    ll end = arr.size()-1;
    // 홀수일 경우
    if(N%2)
    {
        mx = arr[end];
        end--;
    }
    while(start<end)
    {
        ll sum = arr[start]+arr[end];
        mx = max(mx,sum);
        start++;
        end--;
    }
    cout << mx;    
}
