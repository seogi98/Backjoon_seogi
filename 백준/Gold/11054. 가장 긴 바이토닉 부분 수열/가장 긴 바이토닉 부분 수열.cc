#include <iostream>
#include <algorithm>
#include <string.h>
#include <queue>
using namespace std;

int DP[1001]={0,};
int DP2[1001]={0,};
priority_queue<int> pq;
int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    int arr[1001];


    for (int i = 1; i <= N; i++)
    {
        cin >> arr[i];
    }
    DP[1] = 1;

    for(int i=2;i<=N;i++)
    {
        int max=1;
        for(int j=1;j<i;j++)
        {
            if(arr[i]>arr[j])
            {
                if(DP[j]>=max)
                {
                    max = DP[j]+1;
                }
            }
        }
        DP[i] = max;
    }

    for(int i=N;i>=1;i--)
    {
        int max=1;
        for(int j=N;j>i;j--)
        {
            if(arr[i]>arr[j])
            {
                if(DP2[j]>=max)
                {
                    max = DP2[j]+1;
                }
            }
        }
        DP2[i] = max;
    }

    for (int i = 1; i <=N; i++)
    {
        //cout << i << " : "<<DP[i] << ", "<<DP2[i]<<endl;
        pq.push(DP[i]+DP2[i]-1);
    }
    cout<< pq.top();
}
