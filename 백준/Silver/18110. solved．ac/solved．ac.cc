#include <bits/stdc++.h>
#include <algorithm>
#define MAXX 300100
using namespace std;

int main(void)
{
   cin.tie(NULL);
   ios::sync_with_stdio(false);
   int N;
   cin >> N;
   if(N==0)
   {
      cout << "0";
      return 0;
   }
   int diff[MAXX];
   int banNum = floor(N*(0.15)+0.5);
   double ans=0;
   double result=0;
   int resultN = N-2*banNum;
   for(int i=0;i<N;i++)
   {
      cin >> diff[i];
   }
   sort(diff,diff+N);
   for(int i=banNum;i<N-banNum;i++)
   {
      result +=diff[i];
   }
   ans = result/(double)resultN;
   cout << floor(ans+0.5);

}