#include <bits/stdc++.h>
using namespace std;
#define MAX 20
#define INF 299999
typedef long long ll;
int dis(string s1, string s2)
{
    int result=0;
    for(int i=0;i<4;i++)
    {
        if(s1[i]!=s2[i]) result++;
    }
    return result;
}
// 3개 고르기
int dfs(vector<string> arr,vector<string> sum,int idx)
{
    int tmp = INF;
    if(sum.size() == 3) {
        return dis(sum[0],sum[1])+dis(sum[1],sum[2])+dis(sum[0],sum[2]);
    }
    if(idx >=arr.size()) return INF;
    tmp = min(dfs(arr,sum,idx+1),tmp);
    sum.push_back(arr[idx]);
    tmp = min(dfs(arr,sum,idx+1),tmp);
    return tmp;
}
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    while(T--)
    {
        int N;
        int ans=0;
        cin >> N;
        map<string,int> mp;
        for(int i=0;i<N;i++)
        {
            string tmp;
            cin >> tmp;
            if(mp[tmp]>=3) continue;
            mp[tmp]++;
        }
        vector<string> arr;
        for(auto i : mp)
        {
            int dup = i.second;
            for(int j=0;j<dup;j++)
            {
                arr.push_back(i.first);
            }
        }
        ans = dfs(arr,{},0);
        cout << ans << "\n";
    }
}
