#include <bits/stdc++.h>
using namespace std;

int main()
{
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   int N,M;
   cin >> N >>M;
   int ans  =N;
   while(N !=0)
   {
      N=N/M;
      ans+=N;
   }
   cout << ans;
}