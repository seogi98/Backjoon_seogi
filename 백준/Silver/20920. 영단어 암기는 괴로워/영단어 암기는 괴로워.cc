#include<bits/stdc++.h>
using namespace std;
map<string,int> mp;
bool cmp(pair<string,int> p1,pair<string,int> p2)
{
    if(p1.second == p2.second)
    {
        if(p1.first.size() == p2.first.size())
        {
            return p1.first < p2.first;
        }
        return p1.first.size() > p2.first.size();
    }
    return p1.second > p2.second;
}
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N,M;
    cin >> N >> M;
    for(int i=0;i<N;i++)
    {
        string tmp;
        cin >> tmp;
        if(tmp.size()<M) continue;
        mp[tmp]++;
    }
    vector<pair<string,int>> V;
    for(auto i : mp){
        V.push_back(i);
    }
    sort(V.begin(),V.end(),cmp);
    for(int i=0;i<V.size();i++) cout << V[i].first << "\n";
}  