#include<bits/stdc++.h>
using namespace std;
#define MAX 3010
#define DIV 1000000007
// N,K=> 시작 lev로 전환
// 아래로 내려가는 거랑 위로 올라가는거랑 min값 찾는다.
int dp[MAX][MAX];
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N,K;
    cin >> N >> K;
    dp[1][1] = 0;
    // K 짝수 1 줄어들고 홀수면 1 늘어난다.
    // N이 홀수면 dp[n][1] = dp[n-1][1]*2
    // N이 짝수면 dp[n][1] = dp[n-1][1]*2+1
    for(int i=2;i<=N;i++){
        if(i % 2 == 0){
            dp[i][1] = (dp[i-1][1]*2+1)%DIV;
        }
        else{
            dp[i][1] = (dp[i-1][1]*2)%DIV;
        }
    }
    int ans = dp[N][1];
    if(K % 2 == 0 && N % 2 == 0) ans--;
    else if(K % 2 == 0 && N % 2 != 0) ans++;
    cout << ans%DIV;

}