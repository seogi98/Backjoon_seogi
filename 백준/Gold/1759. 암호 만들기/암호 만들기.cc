
#include <bits/stdc++.h>
using namespace std;
#define MAX 21
#define INF 1999999999
//모음
map<char, bool> mo = {{'a', true}, {'e', true}, {'i', true}, {'o', true}, {'u', true}};
set<string> ans;
vector<char> arr;
int L, C;
void dfs(int idx, string sum)
{
    if (sum.size() >= L)
    {
        int moC =0;
        int jaC =0;
        for (int i = 0; i < sum.size(); i++)
        {
            if (mo[sum[i]])
            {
                moC++;
                continue;
            }
            jaC++;
        }
        if(moC >=1 && jaC >=2) ans.insert(sum);
        return;
    }
    if (idx >= C)
        return;
    // 미포함
    dfs(idx + 1, sum);
    // 포함
    sum.push_back(arr[idx]);
    dfs(idx + 1, sum);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> L >> C;
    for (int i = 0; i < C; i++)
    {
        char t;
        cin >> t;
        arr.push_back(t);
    }
    sort(arr.begin(), arr.end());
    dfs(0, "");
    for (auto i : ans)
    {
        cout << i << "\n";
    }
}
