#include <bits/stdc++.h>
using namespace std;
#define MAX 200002

int main()
{
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   int N, Q;
   cin >> N >> Q;
   int A[MAX];
   int ans[MAX];
   for (int i = 0; i < N; i++)
   {
      cin >> A[i];
   }
   int result=0;
   for (int j = 0; j < N; j++)
   {
      ans[j] = A[j % N] * A[(j + 1) % N] * A[(j + 2) % N] * A[(j + 3) % N];
      result +=ans[j];
   }
   int answer = result;
   for(int i=0;i<Q;i++)
   {
      int r;
      cin >> r;
      if(--r == -1)
      {
         r = N-1;
      }
      for(int j=0;j<4;j++)
      {
         ans[(r)%N] = -ans[(r)%N]; 
         answer += 2*ans[(r)%N];
         if(--r ==-1)
         {
            r = N-1;
         }
      }
      cout << answer << "\n";
   }
}