#include <string>
#include <vector>
#include <iostream>

using namespace std;

int N;
int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int pk[10001];
    int dp[10001];

    cin >> N;
    for(int i=1;i<=N;i++)
    {
        cin >> pk[i];
    }
    dp[0] = 0;
    dp[1] = pk[1];
    dp[2] = max(pk[2],pk[1]+pk[1]);
    //cout <<"2 : "<< dp[2] << endl;
    for(int i=3;i<=N;i++)
    {
        int max=0;
        for(int j=1;j<=i;j++)
        {
            int tmp = dp[i-j]+pk[j];
            if(tmp > max)
            {
                max = tmp;
            }
        }
        dp[i] = max;
        //cout <<i<<": "<< dp[i] << endl;
    }
    cout << dp[N];
}