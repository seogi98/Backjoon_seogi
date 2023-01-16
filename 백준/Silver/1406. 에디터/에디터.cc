#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    deque<char> L,R;
    int N;
    string str;
    string answer;
    cin >> str;
    cin >> N;
    for(int i=0;i<str.size();i++)
    {
        L.push_back(str[i]);
    }
    for(int i=0;i<N;i++)
    {
        char op;
        cin >> op;
        if(op == 'L')
        {
            if(L.empty()) continue;
            R.push_back(L.back());
            L.pop_back();
            continue;
        }
        if(op == 'D')
        {
            if(R.empty()) continue;
            L.push_back(R.back());
            R.pop_back();
            continue;
        }
        if(op == 'B')
        {
            if(L.empty()) continue;
            L.pop_back();
            continue;
        }
        if(op == 'P')
        {
            char input;
            cin >> input;
            L.push_back(input);
        }
    }
    while(!L.empty())
    {
        answer.push_back(L.front());
        L.pop_front();
    }
    while(!R.empty())
    {
        answer.push_back(R.back());
        R.pop_back();
    }
    cout << answer;
}