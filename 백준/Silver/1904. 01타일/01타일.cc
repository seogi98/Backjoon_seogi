#include <cstdio>
using namespace std;

#define MOD 15746

int main () {

    int N, i;

    scanf("%d", &N);
    long long dp[N+1];
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;

    for (i = 3; i <= N; i++ ) dp[i] = (dp[i-1] + dp[i-2]) % MOD;
    printf("%lld\n", dp[N]);

    return 0;
}