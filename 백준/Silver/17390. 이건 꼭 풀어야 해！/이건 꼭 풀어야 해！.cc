#include <iostream>
#include <algorithm>
#include<stdio.h>
using namespace std;

int main()
{
int N,Q;
int arr[300001]={0,};
int DP[300001]={0,};
int a,b;
    scanf("%d %d",&N,&Q);
    for(int i=1;i<=N;i++)
    {
        scanf("%d",&arr[i]);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                             
    }
    sort(arr+1,arr+N+1);
    for(int i=1;i<=N;i++)
    {
        DP[i] +=arr[i]+DP[i-1];
    }

    for(int i=1;i<=Q;i++)
    {
        scanf("%d %d",&a ,&b);
        printf("%d\n",DP[b]-DP[a-1]);
    }
}
