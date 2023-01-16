#include <bits/stdc++.h>
#include <algorithm>
#define MAXX 100001
using namespace std;


int main(void)
{
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   int N, M;
   cin >> N >> M;
   int prefix[MAXX];
   prefix[0]=0;
   for (int i = 1; i <= N; i++)
   {
      int T;
      cin >> T;
      if(i==1){prefix[1] = T;continue;}
      prefix[i] = prefix[i-1]+T;
   }
   for (int i = 0; i < M; i++)
   {
      int start, end;
      cin >> start >> end;
      cout << prefix[end] - prefix[start-1] << "\n";   
   }
}
