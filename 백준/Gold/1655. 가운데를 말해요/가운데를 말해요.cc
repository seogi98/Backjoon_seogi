#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX 100010
vector<int> tree(MAX*5,0);
void init(int node,int start,int end,int key)
{
	if(start>key || end < key)
	{
		return;
	}
	if(start == end)
	{
		tree[node] += 1;
		return;
	}
	int mid = (start+end)/2;
	init(node*2,start,mid,key);
	init(node*2+1,mid+1,end,key);
	tree[node] = tree[node*2]+tree[node*2+1];
}
int query(int node,int start,int end,int key)
{
	if(start==end) return start;
	int mid = (start+end)/2;
	if(key <= tree[node*2]) return query(node*2,start,mid,key);
	else return query(node*2+1,mid+1,end,key-tree[node*2]);
}
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin >> N;
	for(int i=1;i<=N;i++)
	{
		int T;
		cin >> T;
		init(1,1,MAX,T+11000);
		cout << query(1,1,MAX,(i+1)/2)-11000 << "\n";
	}
}