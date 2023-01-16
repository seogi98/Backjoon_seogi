#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int arr[21];
int ans = 0;
int DP[100];
int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int T;
    int N;
    cin >> T;
    DP[1] = 1;
    DP[2] = 2;
    DP[3] = 4;
    for (int i = 4; i <= 11; i++)
    {
        for (int j = 1; j <= 3; j++)
        {
            DP[i] += DP[i - j];
        }
    }
    while (T--)
    {
        cin >> N;
        cout << DP[N] << "\n";
    }
}