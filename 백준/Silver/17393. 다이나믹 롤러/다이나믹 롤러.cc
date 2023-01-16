#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#define MAX 1001
using namespace std;
#define INF 2000
#define MAXX 20001

long long N;
long long A[500005];
long long B[500005];
long long DP[500005];

long long minSearch(long long key,long long start,long long end)
{
    long long mid;
    while(start < end)
    {
        mid =(end+start)/2;
        if(B[mid]<=key)
        {
            start = mid+1;
        }
        else            
        {
            end = mid;
        }   
    }
    return end;
}



int main()
{
    cin >> N;
    for(long long i=1;i<=N;i++)
    {

        cin >> A[i];
    }
    for(long long i=1;i<=N;i++)
    {
        cin >> B[i];
    }
    for(long long i=1;i<=N;i++)
    {
        cout << minSearch(A[i],0,N+1)-i-1<< " ";
    }
}
