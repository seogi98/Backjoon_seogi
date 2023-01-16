#include <bits/stdc++.h>
using namespace std;
#define MAX 100
#define INF 1999999999
bool cmp(pair<string,string> p1, pair<string,string>p2)
{
    return p1.first < p2.first;
}
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string S,E,Q;
    set<string> chat;
    set<string> result;
    vector<pair<string,string>> V;
    cin >> S >> E >> Q;
    while(!cin.eof())
    {
        string T,N;
        cin >> T >> N;
        V.push_back({T,N});
    }
    sort(V.begin(),V.end(),cmp);
    for(int i=0;i<V.size();i++)
    {
        string T,N;
        T = V[i].first;
        N = V[i].second;
        if(T<=S)
        {
            chat.insert(N);
        }
        if(T>=E && T <=Q)
        {
            if(!chat.insert(N).second)
            {
               result.insert(N);
            }
            else
            {
                chat.erase(N);   
            }
        }
    }
    cout << result.size();

}