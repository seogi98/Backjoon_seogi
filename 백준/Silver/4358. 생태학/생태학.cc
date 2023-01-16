#include <bits/stdc++.h>
using namespace std;
#define MAX 100
#define INF 1999999999
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    map<string,double,less<string>> M;
    double total=-1;
    while(!cin.eof())
    {
        string T;
        getline(cin,T);
        M[T]++;
        total++; 
    }
    for(auto &I : M)
    {
        if(I.first.empty()) continue;
        double result = M[I.first]/total;
        cout << fixed;
        cout.precision(4);
        cout << I.first << " " << result*100 << "\n";
    }
}