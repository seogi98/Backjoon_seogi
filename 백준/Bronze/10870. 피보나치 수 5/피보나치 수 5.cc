#include <iostream>
#include <algorithm>
#include <string.h>
#include <queue>

using namespace std;
int result=1;
int DP[100];
int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    DP[0] = 0;
    DP[1] = 1;
    for(int i=2;i<=N;i++)
    {
        DP[i] = DP[i-1]+DP[i-2];
    }
    cout << DP[N];
    
}