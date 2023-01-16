#include <bits/stdc++.h>
using namespace std;
#define MAX 500010
#define INF 1999999999
pair<int, int> tree[MAX]; // min , max
int A[MAX];
pair<int, int> init(int start, int end, int curNode)
{
    if (start == end)
    {
        return tree[curNode] ={ A[start], A[start] };
    }
    pair<int,int> L = init(start, (start+end)/2, curNode*2);
    pair<int,int> R = init((start+end)/2+1, end, curNode*2+1);
    return tree[curNode] ={
        min(L.first,R.first),
        max(L.second, R.second)
    };
}
pair<int, int> find(int left, int right, int start, int end, int curNode)
{
    if (start > right || end < left)
    {
        return { INF, 0 };
    }
    else if (left<=start && right>=end)
    {
        return tree[curNode];
    }
    pair<int,int> L = find(left, right, start, (start+end)/2, curNode*2);
    pair<int,int> R = find(left, right, (start+end)/2+1, end, curNode*2+1);
    return {
        min(L.first,R.first),
        max(L.second,R.second)
    };
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int N, M; // DVD , 사건수
    cin >> N >> M;
    for(int i =1;i<=N;i++)
    {
        cin >> A[i];
    }
    init(1,N,1); 
    for(int i=0;i<M;i++)
    {
        int left,right;
        cin >> left >> right;
        pair<int,int> tmp;
        tmp = find(left,right,1,N,1);
        cout << tmp.first << " "<<tmp.second << "\n";
    }
}