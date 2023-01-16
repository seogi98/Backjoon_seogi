#include <bits/stdc++.h>
#include <regex>
using namespace std;
#define MAX 10000
#define INF 200000000000
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    regex re("(100+1+|01)+");

    string str;
    cin >> str;
    if (regex_match(str, re))
    {
        cout << "SUBMARINE\n";
    }
    else
    {
        cout << "NOISE\n";
    }
}