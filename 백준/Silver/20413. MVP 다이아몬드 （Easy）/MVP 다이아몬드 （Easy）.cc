#include <bits/stdc++.h>
using namespace std;
#define MAX 2010
#define INF 2999999998000
typedef long long ll;
// dp[i-1] + cur = mvp[cur] - 1

// dp[i] = mvp[cur]-1 - dp[i-1]

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N; 
    cin >> N;
    int dp[MAX];
    map<char,int> mvp;
    cin >> mvp['B'];
    cin >> mvp['S'];
    cin >> mvp['G'];
    cin >> mvp['P'];
    dp[0] =0;
    string str;
    cin >> str;
    for(int i=1;i<=N;i++)
    {
        char cur = str[i-1];
        if(cur == 'D') {
            dp[i] = mvp['P'];
            continue;
        }
        dp[i] = mvp[cur]-dp[i-1]-1;
    }
    int answer=0;
    for(int i=1;i<=N;i++)
    {
        answer +=dp[i];
    }
    cout << answer;
}


