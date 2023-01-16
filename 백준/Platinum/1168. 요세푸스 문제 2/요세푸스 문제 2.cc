#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX 2000010
#define INF 2147483611
vector<int> tree(MAX*5,0);
void update(int node,int start,int end,int key,int v)
{
	//not include range
	if(key < start || end < key)
	{
		return ;
	}
	//last node => +v check
	if(start==end)
	{
		//  case v = 1: tree[node] = 1 , case v = 2: tree[node] =0
		tree[node]+=v;
		return;
	}
	int mid = (start+end)/2;
	//left
	update(node*2,start,mid,key,v);
	//right
	update(node*2+1,mid+1,end,key,v);
	//left+right
	tree[node] = tree[node*2]+tree[node*2+1];
}
void print(vector<int> P)
{
    cout <<"<";
    for(int i=0;i<P.size()-1;i++)
    {
        cout << P[i] << ", ";
    }
    cout << P[P.size()-1] << '>';
}
int query(int node, int start,int end,int key)
{
	//last node return start
	if(start==end) return start;
	
	//left node : kth num
	if(key <=tree[node*2]) return query(node*2,start,(start+end)/2,key);
	
	//right node : 
	else return query(node*2+1,(start+end)/2+1,end,key-tree[node*2]);
}
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N,K;
    cin >> N >> K;
    vector<int> ans;
    for(int i=1;i<=N;i++)
    {
        update(1,1,MAX,i,1);
    }
    int cur = 0;
    int mx = N;
    for(int i=1;i<=N;i++)
    {
        cur = (cur+K);
        while(cur > mx) cur -=mx;
        int tmp = query(1,1,MAX,cur);
        ans.push_back(tmp);
        update(1,1,MAX,tmp,-1);
        mx --;
        cur --;
    }
    print(ans);
}