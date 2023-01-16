#include <bits/stdc++.h>
using namespace std;

int main()
{
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   // 2 3 4 6 8 9 10
   int N,M;
   cin >> N >>M;
   int arrM[1001];
   bool isCheck[1001];
   memset(isCheck,false,sizeof(isCheck));
   for(int i=0;i<M;i++)
   {
      cin >> arrM[i];
   }
   for(int i=0;i<M;i++)
   {
      int cur = arrM[i];
      for(int j=cur;j<=N;j +=cur)
      {
         isCheck[j] = true;
      }
   }
   int ans=0;
   for(int i=1;i<=N;i++)
   {
      if(isCheck[i])
      {
         ans+=i;
      }
   }
   cout << ans;
   
}