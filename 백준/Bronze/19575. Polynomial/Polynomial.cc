#include <bits/stdtr1c++.h>
using namespace std;
#define MAX 1000010
#define DIV 1000000007
long long N, X;
long long P[MAX];
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> X;
    long long result = 0;
    for (int i = 0; i <= N; i++)
    {
        int A, I;
        cin >> A >> I;
        P[I] = A;
    }
    if(N==0)
    {
        cout << P[0]%DIV;
        return 0;
    }
    result = (P[N] * X)%DIV;
    for (int i = N - 1; i >= 0; i--)
    {
        result = (P[i]+result) % DIV;
        if(i==0) break;
        result = (result*X) % DIV;
    }
    cout << (result  % DIV);
}