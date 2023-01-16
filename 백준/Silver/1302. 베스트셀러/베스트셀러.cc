#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    map<string, int> M;
    pair<string, int> answer;
    answer = {"", 0};
    for (int i = 0; i < N; i++)
    {
        string str;
        cin >> str;
        M[str]++;
    }
    for (auto it : M)
    {
        if (it.second > answer.second)
        {
            if (it.second == answer.second && it.first < answer.first)
            {
                answer = {it.first, it.second};
                continue;
            }
            answer = {it.first, it.second};
        }
    }
    cout << answer.first;
}