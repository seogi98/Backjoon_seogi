#include <bits/stdc++.h>
#include<regex>
using namespace std;
#define MAX 10000
#define INF 200000000000
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    regex re("(100+1+|01)+");
    int N;
    cin >> N;
    for(int i=0;i<N;i++)
    {
        string str;
        cin >> str;
        if(regex_match(str,re)){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
    }
}