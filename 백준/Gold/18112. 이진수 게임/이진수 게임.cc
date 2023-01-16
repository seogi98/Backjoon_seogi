#include <bits/stdc++.h>
#include <algorithm>
#define MAXX 700
#define MAX 987654321
using namespace std;

string com_num(string A,int i)
{
   A[i] == '1' ? A[i] = '0' : A[i] = '1';
   return A;
}
string sub_num(string A)
{
   int L = A.length()-1;
   if(A[L] == '1')
   {
      A[L] = '0';
      return A;
   }
   A[L] = '1';
   bool isDown = true;
   for(int i=L-1;i>0;i--)
   {
      if(!isDown)
      {
         break;
      }
      if(A[i]=='1' && isDown)
      {
         isDown = false;
         A[i] = '0';
         break;
      }
      if(A[i]=='0' && isDown)
      {
         A[i] = '1';
         isDown = true;
         continue;
      }
   }
   if(isDown)
   {
      A.clear();
      for(int i=0;i<L;i++)
      {
         A.push_back('1');
      }
   }
   return A;
}
string add_num(string A)
{
   int L = A.length()-1;
   if(A[L] == '0')
   {
      A[L] = '1';
      return A;
   }
   A[L] ='0';
   bool isUp = true;
   for(int i=L-1;i>0;i--)
   {
      if(!isUp)
      {
         break;
      }
      if(A[i]=='1' && isUp)
      {
         isUp = true;
         A[i] = '0';
         continue;
      }
      if(A[i]=='0' && isUp)
      {
         A[i] = '1';
         isUp = false;
         break;
      }
   }
   if(isUp)
   {
      A.clear();
      A.push_back('1');
      for(int i=0;i<=L;i++)
      {
         A.push_back('0');
      }
   }
   return A;
}
int main(void)
{
   string A,B;
   cin >> A >> B;
   queue<pair<string,int>> q;
   q.push({A,0});
   vector<string> isEx;
   int mn = MAX;
   while(!q.empty())
   {
      string curS = q.front().first;
      int curN = q.front().second;
      q.pop();
      if(curS == B)
      {
         cout << curN;
         return 0;
      }
      bool isbk = false;
      for(int i=0;i<isEx.size();i++)
      {
         if(isEx[i] == curS)
         {
            isbk = true;
            break;
         }
      }
      if(isbk)
      {
         continue;
      }
      if(curS.size()>13 || curS.size()<=0)
      {
         continue;
      }
      //cout <<"curS : " <<  curS << " curN : "  << curN << "\n";
      isEx.push_back(curS);
      //cout << curS<<"\n";
      for(int i=1;i<curS.length();i++)
      {
         string comS = com_num(curS,i);
         q.push({comS,curN+1});
      }
      q.push({add_num(curS),curN+1});
      if(curS!="0")
      {
         q.push({sub_num(curS),curN+1});
      }
   }
   cout << mn;
}

