#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdlib.h>
#include <queue>
#include <vector>
using namespace std;


int N;

void fibo(int n)
{
    int DP[100][2];
    DP[0][0] = 1;
    DP[0][1] = 0;
    DP[1][0] = 0;
    DP[1][1] = 1;
    for (int i = 2; i <= n; i++)
    {
        for (int j = 0;j < 2; j++)
        {
            DP[i][j] = DP[i-1][j]+DP[i-2][j];
        }
    }
    cout << DP[n][0] << " " << DP[n][1]<<"\n";
    return;
    
}
int main(void)
{
    int T;
    int Tm;
    cin  >> T;
    while(T--)
    {
        cin >> Tm;
        fibo(Tm);
    }
    
    

}
