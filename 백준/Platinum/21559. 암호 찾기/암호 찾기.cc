
#include<bits/stdc++.h>
using namespace std;
#define MAX 100000
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N,K;
    cin >> N >> K;
    string str1,str2;
    cin >> str1 >> str2;
    map<string,int> mp;
    for(int i=0;i<=N-K;i++){
        string tmp1 = str1.substr(i,K);
        string tmp2 = str2.substr(i,K);
        mp[tmp1]++;
        mp[tmp2]++;
    }
    int ans=0;
    for(auto i : mp){
        if(i.second >=2) ans++;
    }

    cout << ans;
}