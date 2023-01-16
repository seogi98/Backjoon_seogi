#include <bits/stdc++.h>
using namespace std;
#define MAX 106
int main(void)
{
   cin.tie(NULL);
   ios::sync_with_stdio(false);
   int N;
   cin >> N;
   int A = (N-1)/4;
   int B = N%4;
   if(!(A%2))
   {
      B==0?cout << 4:cout << B;
   } 
   else
   {
      B==0?cout << 2:cout << 6-B;
   }
}