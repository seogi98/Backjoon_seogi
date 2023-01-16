#include <bits/stdc++.h>
using namespace std;
#define MAX 100010

int G[5];
void move(int N, bool isR)
{
    int curNum = G[N];
    int tmp;
    if (isR)
    {
        tmp = curNum & 1;
        curNum = curNum >> 1;
        curNum |= (tmp << 7);
    }
    else
    {
        tmp = curNum >= 128;
        curNum = curNum << 1;
        curNum |= (tmp);
        if (curNum >= (1 << 8))
        {
            curNum -= (1 << 8);
        }
    }
    //cout << "N : " << N << endl;
    //cout << bitset<8>(curNum) << endl;
    G[N] = curNum;
}
void rotation(int N, int D)
{
    bool isR;
    D > 0 ? isR = true : isR = false;
    bool isR2 = !isR;
    pair<bool, bool> gcon[6];
    for (int i = 1; i <= 4; i++)
    {
        gcon[i].second = (G[i] & (1 << 5)) == (1 << 5);
        gcon[i].first = (G[i] & (1 << 1)) == (1 << 1);
    }
    for (int j = N; j <= 4; j++)
    {
        move(j, isR);
        if (gcon[j].second == gcon[j + 1].first)
        {
            break;
        }
        isR = !isR;
    }
    if(gcon[N].first == gcon[N - 1].second)
    {
        return;
    }
    for (int j = N - 1; j >= 1; j--)
    {
        move(j, isR2);
        if (gcon[j].first == gcon[j - 1].second)
        {
            break;
        }
        isR2 = !isR2;
    }
}
int main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    int K;
    for (int i = 1; i <= 4; i++)
    {
        string tmp;
        cin >> tmp;
        for (int j = 0; j < 8; j++)
        {
            G[i] += tmp[7 - j] == '1' ? (pow(2, j)) : 0;
        }
    }
    cin >> K;
    for (int i = 0; i < K; i++)
    {
        int N, D;
        cin >> N >> D;
        rotation(N, D);
    }
    int result = 0;
    // for (int i = 1; i <= 4; i++)
    // {
    //     cout << bitset<8>(G[i]) << endl;
    // }
    for (int i = 1; i <= 4; i++)
    {
        G[i] >= (1<<7) ? result += pow(2, i - 1) : 0;
    }
    cout << result;
}