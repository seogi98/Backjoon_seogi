#include <bits/stdc++.h>
using namespace std;
#define MAX 10000
#define INF 200000000000
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string str;
    cin >> str;
    int dup = 0;
    char pre = '(';
    int ans = 0;
    for (int i = 0; i < str.size(); i++)
    {
        char cur = str[i];
        if (cur == '(')
            dup++;
        if (cur == ')')
        {
            if (pre == '(')
            {
                ans += (dup-1);
            }
            else{
                ans+=1;
            }
            dup--;
        }
        pre = cur;
    }
    cout << ans;
}