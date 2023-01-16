#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    deque<int> q;
    vector<int> ans;
    int N, K, M;
    cin >> N >> K >> M;
    for (int i = 1; i <= N; i++)
    {
        q.push_back(i);
    }
    int num = 0;
    bool isR = true;
    while (!q.empty())
    {
        if (num % M == 0)
        {
            isR = !isR;
        }
        if (isR)
        {
            for (int i = 1; i <= K - 1; i++)
            {
                q.push_front(q.back());
                q.pop_back();
            }
            ans.push_back(q.back());
            q.pop_back();
            num++;
            continue;
        }
        for (int i = 1; i <= K - 1; i++)
        {
            q.push_back(q.front());
            q.pop_front();
        }
        ans.push_back(q.front());
        q.pop_front();
        num++;
    }
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << "\n";
    }
}
