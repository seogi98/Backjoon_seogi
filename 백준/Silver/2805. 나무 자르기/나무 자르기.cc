#include <iostream>
#include <algorithm>
#include <vector>
#include<queue>

using namespace std;

long long N,M;
vector<long long> Tr;
priority_queue<long long> pq;

long long restLen(long long mid)
{
    long long result=0;
    for(long long i=0;i<Tr.size();i++)
    {
        long long rest = Tr[i]-mid;
        if(rest>0)
        {  
            result+=rest;   
        }
    }
    return result;
}
long long searchLen(long long start,long long end)
{
    long long ans=0;
    while(start<=end)
    {
        long long mid = (start+end)/2;
        long long len = restLen(mid);
        if(len >= M)//가져가려는 나무의 길이보다 len이 짧을경우 mid값을 줄여야한다.
        {
            ans = max(ans,mid);
            start  = mid+1;
        }
        else//길이보다 길경우 mid값을 늘려야한다.
        {
            end = mid-1;
        }

    }
    return ans;
}
int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> N >> M;
    long long max=0;
    for(long long i=0;i<N;i++)
    {
        long long T;
        cin >> T;
        if(max <T)
        {
            max = T;
        }
        Tr.push_back(T);
    }
    cout << searchLen(1,max);
}