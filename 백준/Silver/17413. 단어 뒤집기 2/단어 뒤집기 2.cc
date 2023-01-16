#include <bits/stdc++.h>
using namespace std;
#define MAX 300

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    stack<char> rv; // 
    queue<char> fw; // <>
    string result;
    bool isrv = true;
    string str;
    getline(cin,str);
    for (int i = 0; i < str.size(); i++)
    {
        char T = str[i];
        if (T == '<')
        {
            while(!rv.empty())
            {
                result.push_back(rv.top());
                rv.pop();
            }
            isrv = false;
        }
        if(T == '>')
        {
            while(!fw.empty())
            {
                result.push_back(fw.front());
                fw.pop();
            }
            result.push_back(T);
            isrv = true;
            continue;
        }
        if(T == ' ' && isrv)
        {
            while(!rv.empty())
            {
                result.push_back(rv.top());
                rv.pop();
            }
            result.push_back(T);
            continue;
        }
        if (isrv)
        {
            rv.push(T);
        }
        if(!isrv)
        {
            fw.push(T);
        }
    }
    while(!rv.empty())
    {
        result.push_back(rv.top());
        rv.pop();
    }
    while(!fw.empty())
    {
        result.push_back(fw.front());
        fw.pop();
    }
    cout << result;
}
