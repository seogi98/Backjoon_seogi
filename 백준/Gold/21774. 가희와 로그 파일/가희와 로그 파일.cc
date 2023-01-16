#include<bits/stdc++.h>
using namespace std;
#define MAX 100000
// 년 일 월
vector<int> V[10];
// 정렬 여부 판단
// bool vst[10][40][40][40];
void parse(const string& str, vector<string>& values , string & delimiter){
   string::size_type Fpos = str.find_first_not_of(delimiter,0);
   string::size_type Lpos = str.find_first_of(delimiter,Fpos);
   while(string::npos != Fpos || string::npos !=Lpos){
      values.push_back(str.substr(Fpos,Lpos-Fpos));
      Fpos = str.find_first_not_of(delimiter,Lpos);
      Lpos = str.find_first_of(delimiter,Fpos);
   }
}
int convertTimeStoi(string str){
    int h = atoi(str.substr(0,2).c_str())*3600;
    int m = atoi(str.substr(3,5).c_str())*60;
    int s = atoi(str.substr(6,8).c_str());
    return h+m+s;
}
int dayDiv(string str){
    int res = 0;
    res += atoi(str.substr(2,4).c_str())*60*60*24*31*12;
    res += atoi(str.substr(5,7).c_str())*60*60*24*31;
    res += atoi(str.substr(8,10).c_str())*60*60*24;
    res += atoi(str.substr(11,13).c_str())*60*60;
    res += atoi(str.substr(14,16).c_str())*60;
    res += atoi(str.substr(17,19).c_str());
    return res;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N,Q;
    cin >> N >> Q;
    cin.ignore();
    for(int i=0;i<N;i++){
        string str;
        getline(cin,str);
        int tmp = dayDiv(str);
        int ttmp = str[20]-'0';
        V[ttmp].push_back(tmp);
    }
    for(int i=1;i<=6;i++){
        sort(V[i].begin(),V[i].end());
    }
    for(int i=0;i<Q;i++){
        int ans=0;
        string str;
        string del = "#";
        getline(cin,str);
        vector<string> values;
        parse(str,values,del);
        int st = dayDiv(values[0]);
        int ed = dayDiv(values[1]);
        int lev = atoi(values[2].c_str());
        for(int j=lev;j<=6;j++)
        {
           ans += (upper_bound(V[j].begin(),V[j].end(),ed)-lower_bound(V[j].begin(),V[j].end(),st));
        }   
        cout << ans << "\n";
    }
}