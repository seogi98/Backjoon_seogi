#include <bits/stdc++.h>
using namespace std;
#define MAX 101
#define INF 1987654321
map<char,char> M = {{'E','I'},{'I','E'},{'S','N'},{'N','S'},{'T','F'},{'F','T'},{'J','P'},{'P','J'}};
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string mbti;
    cin >> mbti;
    for(int i=0;i<mbti.size();i++)
    {
        cout << M[mbti[i]];
    }
}



