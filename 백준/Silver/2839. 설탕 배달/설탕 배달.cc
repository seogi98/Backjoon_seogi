#include<bits/stdc++.h>
using namespace std;
#define MAX 5001
vector<int> dp(MAX,MAX);
int result = -1;
int main(void){
    int N;
    cin >> N;
    dp[3] = 1,dp[5]=1;
    for(int i=6;i<=N;i++)dp[i] = min(dp[i-3]+1,dp[i-5]+1);
    if(dp[N] <MAX) result = dp[N];
    cout << result;
}