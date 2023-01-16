#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <math.h>
#include <stack>
#include <string.h>
#define MAXX 2000
using namespace std;
int N;
int dp[MAXX][MAXX]; // dp[string A][string B]
int main()
{
   cin.tie(NULL);
   ios::sync_with_stdio(false);
   string A, B;
   cin >> A >> B;
   // 만약 A[i] == B[i]이면 dp[i][j] = dp[i-1][j]+1
   bool isCheck = false;
   for (int i = 0; i < B.length(); i++)
   {
      for (int j = 0; j < A.length(); j++)
      {
         dp[i][j] = 0;
      }
   }
   for (int i = 1; i <= B.length(); i++)
   {
      for (int j = 1; j <= A.length(); j++)
      {
         char at = A[j-1];
         char bt = B[i-1];
         if (A[j-1] == B[i-1])
         {
            dp[i][j] = dp[i - 1][j-1] + 1;
         }
         else
         {
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
         }
      }
   }
   // for (int i = 2; i <= B.length()+1; i++)
   // {
   //    for (int j = 2; j <= A.length()+1; j++)
   //    {
   //     cout << dp[i-1][j-1]<< " ";
   //    }
   //    cout << "\n";
   // }
   cout << dp[B.length()][A.length()];
}
