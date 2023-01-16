#include <bits/stdc++.h>
using namespace std;

int main()
{
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   int N;
   cin >> N;
   int arrNum[60];
   memset(arrNum,0,sizeof(arrNum));
   for(int i=0;i<N;i++)
   { 
      int T;
      cin >> T;
      arrNum[T]++;
   }
   string str;
   cin.ignore();
   getline(cin,str);
   for(int i=0;i<str.length();i++)
   {
      int cur = str[i];
      if( cur == ' ')
      {
         arrNum[0]--;
         continue;
      }
      if(cur >= 'A' && cur <='Z')
      {
         arrNum[cur-'A'+1]--;
         continue;
      }
      if(cur >= 'a' && cur <='z')
      {
         arrNum[cur-'a'+27]--;
         continue;
      }
   }
   for(int i=0;i<60;i++)
   {
      if(arrNum[i]!=0)
      {
         cout << "n";
         return 0;
      }
   }
   cout << "y";

}