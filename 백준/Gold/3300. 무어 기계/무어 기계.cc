#include <bits/stdc++.h>
#include <regex>
using namespace std;
#define MAX 10000
#define INF 200000000000
vector<string> convert(string str)
{
    vector<string> result;
    for(int i=0;i<=str.size();i++)
    {
        string curStr = str;
        char cur = str[i];
        if(cur == '_')
        {
            for(char a = 'A'; a<='Z';a++)
            {
                curStr[i] = a;
                result.push_back(curStr);
            }
            return result;
        }
    }
}
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    while (T--)
    {
        string str,str2;
        cin >> str >> str2;
        vector<string> strV = convert(str);
        vector<pair<string,int>> answer;
        for(int i=0;i<strV.size();i++)
        {
            regex re(strV[i]);
            if (regex_match(str2, re))
            {
                answer.push_back({str2,i});
            }
        }
        char ans;
        if(answer.size() == 0)
        {
            ans = '!';
        }
        else if(answer.size() == 1)
        {
            ans = 'A'+answer[0].second;
        }
        else {
            ans = '_';
        }
        cout << ans << "\n";
    }
}