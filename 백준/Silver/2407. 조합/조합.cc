#include <bits/stdc++.h>
#define MAX 200
using namespace std;
string dp[MAX][MAX]; // DP[N][M]
// nCm  = n-1Cm + nCm-1;
string bigNumAdd(string num1, string num2)
{
    long long sum = 0;
    string result;
    //1의 자리부터 더하기 시작한다
    while (!num1.empty() || !num2.empty() || sum)
    {
        if (!num1.empty())
        {
            sum += num1.back() - '0';
            num1.pop_back();
        }
        if (!num2.empty())
        {
            sum += num2.back() - '0';
            num2.pop_back();
        }
        //다시 string 형태로 만들어 push_back
        result.push_back((sum % 10) + '0');
        sum /= 10;
    }
    //1의 자리부터 result에 넣었으므로 뒤집어줘야한다
    reverse(result.begin(), result.end());
    return result;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    long long N, M;
    cin >> N >> M;
    char buffer[200] = {0};
    for (int i = 0; i <= N; i++)
    {
        for (int j = 0; j <= N; j++)
        {
            dp[i][j] ="";
        }
    }
    for (int i = 1; i <= N; i++)
    {
        dp[i][1] = to_string(i);
        dp[i][i] = "1";
    }
    for (int i = 3; i <= N; i++)
    {
        for (int j = 2; j <= N; j++)
        {
            dp[i][j] = bigNumAdd(dp[i - 1][j], dp[i - 1][j - 1]);
        }
    }
    cout << dp[N][M];
}