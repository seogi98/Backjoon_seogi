#include <bits/stdc++.h>
using namespace std;
#define MAX 1010
bool cmp(pair<int,int> p1,pair<int,int> p2)
{
    return p1.first > p2.first;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    vector<pair<int,int>> P;
    for(int i=1;i<=9;i++)
    {
        int n;
        cin >> n;
        P.push_back({n,i});
    }
    sort(P.begin(),P.end(),cmp);
    cout << P.front().first << "\n";
    cout << P.front().second;
}
