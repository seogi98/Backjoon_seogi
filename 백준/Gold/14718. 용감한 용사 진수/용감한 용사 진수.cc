#include <bits/stdc++.h>
using namespace std;
// 최소의 스텟 포인트
#define INF 1987654321
struct sol
{
    int str;
    int dex;
    int in;
};
set<int> S[3];
vector<sol> V;
bool duel(sol s1, sol jin)
{
    if (s1.dex > jin.dex || s1.in > jin.in || s1.str > jin.str)
    {
        return false;
    }
    return true;
}
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N, K;
    cin >> N >> K;
    for (int i = 0; i < N; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        V.push_back({a, b, c});
        S[0].insert(a);
        S[1].insert(b);
        S[2].insert(c);
    }
    int answer = INF;
    for (auto i : S[0])
    {

        for (auto j : S[1])
        {

            for (auto k : S[2])
            {
                int win = 0;
                for (int q = 0; q < V.size(); q++)
                {
                    if (duel(V[q], {i, j, k}))
                    {
                        win++;
                    }
                }
                if (win >= K)
                {

                    answer = min(answer, i + j + k);
                }
            }
        }
    }
    cout << answer;
}