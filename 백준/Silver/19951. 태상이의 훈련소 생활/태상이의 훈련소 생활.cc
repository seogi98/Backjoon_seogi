#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX 500010
vector<int> tree(MAX,0);
vector<int> arr(MAX,0);
void init(int node,int start,int end)
{
	if(start==end)
	{
		tree[node] = arr[start];
		return;
	}
	tree[node] = 0;
	init(node*2,start,(start+end)/2);
	init(node*2+1,(start+end)/2+1,end);
}
void update(int node,int start,int end,int left,int right,int key)
{
	if(right < start || left > end)
	{
		return;
	}
	if(start>=left && right >= end)
	{
		tree[node] += key;
		return;
	}
	int mid = (start+end)/2;
	update(node*2,start,mid,left,right,key);
	update(node*2+1,mid+1,end,left,right,key);
}
int findq(int node,int start,int end,int key,int sum)
{
	if(start > key || end < key)
	{
		return 0;
	}
	if(key == start && start==end)
	{
		return tree[node]+sum;
	}
	sum +=tree[node];
	int mid = (start+end)/2;
	return findq(node*2,start,mid,key,sum)+findq(node*2+1,mid+1,end,key,sum);
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N,M;
	cin >> N >> M;
	for(int i=1;i<=N;i++)
	{
		cin >> arr[i];
	}
	init(1,1,N);
	for(int i=1;i<=M;i++)
	{
		int a,b,k;
		cin >> a >> b >> k;
		update(1,1,N,a,b,k);
	}
	for(int i=1;i<=N;i++)
	{
		cout << findq(1,1,N,i,0) <<" ";
	}
}