#include <bits/stdc++.h>
using namespace std;
#define MAX 50001
int vst[MAX];
map<string,string> mp;
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N,M;
    cin >> N >> M;
    for(int i=0;i<N;i++){
        string str1 , str2;
        cin >> str1 >> str2;
        mp[str1]=str2;
    }
    for(int i=0;i<M;i++){
        string tmp;
        cin >> tmp;
        cout << mp[tmp] << "\n";
    }
}