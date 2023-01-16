#include <bits/stdc++.h>
using namespace std;
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int num[11] = {
        0b1110111,
        0b0010010,
        0b1011101,
        0b1011011,
        0b0111010,
        0b1101011,
        0b1101111,
        0b1010010,
        0b1111111,
        0b1111011};

    int N, K, P, X;
    cin >> N >> K >> P >> X;
    string tmp1 = to_string(X);
    string ori = "";
    for (int j = 0; j < K - tmp1.size(); j++)
    {
        ori.push_back('0');
    }
    ori += tmp1;
    int ans = 0;
    for (int i = 1; i <= N; i++)
    {
        if (i == X)
            continue;
        // K길이 문자열로 전환
        string tmp = to_string(i);
        string cur = "";
        for (int j = 0; j < K - tmp.size(); j++)
        {
            cur.push_back('0');
        }
        cur += tmp;
        // 계산
        int curD = 0;
        for (int j = 0; j < K; j++)
        {
            int ttmp = num[ori[j] - '0'] ^ num[cur[j] - '0'];
            curD += __builtin_popcount(ttmp);
        }
        if (curD <= P)
        {
            ans++;
        }
    }
    cout << ans;
}