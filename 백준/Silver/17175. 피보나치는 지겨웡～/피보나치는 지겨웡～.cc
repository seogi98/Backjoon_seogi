#include <bits/stdc++.h>
using namespace std;

int main()
{
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   long long dp[100];
   int N;
   cin >> N;
   dp[0] =1;
   dp[1] =1;
   for(int i=2;i<=N;i++)
   {
      dp[i] = ((dp[i-1]+dp[i-2])+1)%1000000007;
   }
   cout << dp[N]%1000000007;
}