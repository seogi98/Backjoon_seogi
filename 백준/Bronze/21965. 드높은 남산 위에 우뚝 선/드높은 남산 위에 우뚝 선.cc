#include <bits/stdc++.h>
#define MAX 1000000
using namespace std;
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    vector<int> arr;
    cin >> N;
    bool flag = true;
    int pre = 0;
    string ans = "YES";
    for (int i = 1; i < N; i++)
    {
        int t;
        cin >> t;
        if (i == 0)
        {
            pre = t;
            continue;
        }
        if (flag)
        {
            if (pre >= t)
            {
                flag = false;
            }
        }
        else
        {

            if (pre <= t)
            {
                ans = "NO";
            }
        }
        pre = t;
    }
    cout << ans;
}