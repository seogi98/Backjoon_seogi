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
void update(int index,int change,int start, int end, int curNode)
{
    if(start> index || end < index) return;
    if(start == end)
    {
        tree[curNode] = {A[change],A[change]}; 
        return;
    }
    update(index,change,start,(start+end)/2,curNode*2);
    update(index,change,(start+end)/2+1,end,curNode*2+1);
    tree[curNode] = {min(tree[curNode*2].first,tree[curNode*2+1].first),max(tree[curNode*2].second,tree[curNode*2+1].second)};
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while(T--)
    {
        int N,K; // DVD수 , 사건의 수 
        cin >> N >> K;
        memset(A,0,sizeof(A));
        memset(tree,0,sizeof(tree));
        for(int i=0;i<=N;i++)
        {
            A[i] = i;
        }
        init(0,N-1,1);
        for(int i=0;i<K;i++)
        {
            int Q,left,right;
            cin >> Q >> left >> right;
            if(Q)
            {
                pair<int,int> result = find(left,right,0,N-1,1);
                if(result.first !=left || result.second !=right) 
                {
                    cout << "NO\n";
                    continue;
                }
                cout << "YES\n";
                continue;
            }
            update(left,right,0,N-1,1);
            update(right,left,0,N-1,1);
            int tmp = A[left];
            A[left] = A[right];
            A[right] = tmp;
        }
    }
}