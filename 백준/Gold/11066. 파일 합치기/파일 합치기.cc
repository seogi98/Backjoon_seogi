#include <iostream>
#include <algorithm>
#include<string.h>

using namespace std;
int DP[501][501]; //dp 전체 배열
int arr[501]; //arr 배열
int sum[501]; //전체합

int dpf(int tx,int ty)
{
    if(DP[tx][ty]!=0x3f3f3f3f)
    {
        return DP[tx][ty];
    }
    
    if(tx == ty)
    {
        return DP[tx][ty]=0;
    }

    if(tx +1 ==ty)
    {
        return DP[tx][ty] = arr[tx]+arr[ty];
    }
    for(int mid=tx;mid<ty;++mid)
    {
        int left = dpf(tx,mid);
        int right = dpf(mid+1,ty);
        DP[tx][ty] = min(DP[tx][ty],left+right);
    }
     return DP[tx][ty] += sum[ty] - sum[tx - 1];
}
int main(void)
{
    int T;
    cin >> T;
    while(T--)
    {
        int n;
        memset(DP,0x3f,sizeof(DP));
        //DP[i][j]는 i부터 j까지의 부분합이다. 이때 중간점인 K에서부터
        //i->k k+1 -> j 로 분할한다.
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> arr[i];
            sum[i] = sum[i-1]+arr[i];//전체합
        }
        cout << dpf(1,n)<<endl;

    }
    return 0;
}
