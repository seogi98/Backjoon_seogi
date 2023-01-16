#include<bits/stdc++.h>
using namespace std;
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    map<string,int> ans;
    cin >> N;
    for(int i=0;i<N;i++)
    {
        string tmp;
        cin >> tmp;
        int start = tmp.find('.',0);
        string ex;
        for(int i=start+1; i<tmp.size();i++)
        {
            ex.push_back(tmp[i]);
        }
        ans[ex]++;
    }
    for(auto i : ans)
    {
        cout << i.first << " " << i.second << "\n";
    }
}