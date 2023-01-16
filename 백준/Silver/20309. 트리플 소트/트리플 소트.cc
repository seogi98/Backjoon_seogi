#include<bits/stdc++.h>
using namespace std;
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    string ans = "YES";
    for(int i=1;i<=N;i++)
    {
        int t;
        cin >> t;
        if(i%2 != t%2){
            ans = "NO";
            break;
        }
    }
    cout << ans;
}