#include<bits/stdc++.h>
using namespace std;
#define MAX 100000
map<string,string> P;
void parse(const string& str, vector<string>& values , string & delimiter){
   string::size_type Fpos = str.find_first_not_of(delimiter,0);
   string::size_type Lpos = str.find_first_of(delimiter,Fpos);
   while(string::npos != Fpos || string::npos !=Lpos){
      values.push_back(str.substr(Fpos,Lpos-Fpos));
      Fpos = str.find_first_not_of(delimiter,Lpos);
      Lpos = str.find_first_of(delimiter,Fpos);
   }
}
string unionFind(string cur){
   if(P[cur] == cur){
      return cur;
   }
   return P[cur] = unionFind(P[cur]);
}
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
   int N,M;
   cin >> N >> M;
   cin.ignore();
   for(int i=0;i<N;i++){
      string kingdom;
      getline(cin,kingdom);
      P[kingdom] = kingdom;
   }
   for(int i=0;i<M;i++){
      string tmp;
      getline(cin,tmp);
      vector<string> values;
      string delimiter(",");
      parse(tmp,values,delimiter);
      string k1 = values[0];
      string k2 = values[1];
      string w = values[2];
      string k1P = unionFind(k1);
      string k2P = unionFind(k2);
      if(k1P == k2P){
         if(w == "1"){
            if(k1 != k1P){
               P[k1P] = k1;
               P[k1] = k1;
            }
         }
         if(w == "2"){
            if(k2 != k2P){
               P[k2P] = k2;
               P[k2] = k2;
            }
         }
         continue;
      }
      if(w == "1"){
         P[k2P] = k1P;
      }
      if(w == "2"){
         P[k1P] = k2P;
      }
   }
   int ans=0;
   vector<string> ansV;
   for(auto i : P){
      unionFind(i.first);
      if(i.first == i.second){
         ans++;
         ansV.push_back(i.first);
      }
   }
   cout << ans << "\n";
   sort(ansV.begin(),ansV.end());
   for(auto i : ansV){
      cout << i << "\n";
   }
}