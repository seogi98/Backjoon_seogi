#include <bits/stdc++.h>
using namespace std;
#define MAX 500010
#define INF 1999999999
long long tree[MAX];
long long A[MAX];

long long init(long long start,long long end,long long curNode)
{
    if(start == end) return tree[curNode] = A[start];
    return tree[curNode] = min(init(start,(start+end)/2,curNode*2),init((start+end)/2+1,end,curNode*2+1));
}
long long find(long long left,long long right,long long start,long long end,long long curNode)
{
    //포함되지 않는 경우
    if(left>end || right<start)
    {
        return INF;
    }
    //완전히 포함한 경우
    if(left<=start && right >= end)
    {
        return tree[curNode];
    }
    long long findL = find(left,right,start,(start+end)/2,curNode*2);
    long long findR = find(left,right,(start+end)/2+1,end,curNode*2+1);
    return min(findL,findR);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long N,M;
    cin >> N >> M;
    for(long long i=1;i<=N;i++)
    {
        cin >> A[i];
    }
    init(1,N,1);
    for(long long i=0;i<M;i++)
    {
        long long left,right;
        cin >> left >> right;
        long long result = find(left,right,1,N,1);
        cout << result <<"\n";
    }
}