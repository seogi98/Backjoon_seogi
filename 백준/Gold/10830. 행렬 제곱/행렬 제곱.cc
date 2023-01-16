#include <bits/stdc++.h>
using namespace std;
#define MAX 100000002

vector<vector<long long>> mx(10, vector<long long>(10, 0));
long long N, B;
vector<vector<long long>> mulM(vector<vector<long long>> m1, vector<vector<long long>> m2)
{
    vector<vector<long long>> otm(10, vector<long long>(10, 0));
    for (long long i = 0; i < N; i++) // 가로
    {
        for (long long j = 0; j < N; j++) // 세로
        {
            for (long long k = 0; k < N; k++)
            {
                otm[i][j] += (m1[i][k] * m2[k][j])%1000;
            }
        }
    }
    return otm;
}
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> B;
    for (long long i = 0; i < N; i++)
    {
        for (long long j = 0; j < N; j++)
        {
            cin >> mx[i][j];
        }
    }
    vector<vector<long long>> res(10, vector<long long>(10, 0));
    for (long long i = 0; i < N; i++) // 단위행렬
    {
        res[i][i] = 1;
    }
    while (B)
    {
        long long tmpB = B;
        if ((B % 2)) // 홀수일 경우
        {
            res = mulM(res, mx);
            B--;
        }
        else
        {
            mx = mulM(mx, mx);
            B /= 2;
        }
    }
    for (long long i = 0; i < N; i++)
    {
        for (long long j = 0; j < N; j++)
        {
            cout << res[i][j]%1000 << " ";
        }
        cout << "\n";
    }
}
