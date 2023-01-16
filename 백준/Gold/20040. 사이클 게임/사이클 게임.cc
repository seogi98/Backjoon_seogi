// 백준 20040번 사이클 게임
// node1 , node2의 루트노드가 같을경우 cycle
#include <bits/stdc++.h>
using namespace std;
#define MAX 500001
#define INF 987654321
int P[MAX];
int findP(int cur)
{
	if(cur == P[cur])
	{
		return cur;
	}
	return P[cur] = findP(P[cur]);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N,M;
	int ans=0;
	cin >> N >> M;
	for(int i=1;i<=N;i++)
	{
		P[i] = i;
	}
	for(int i=1;i<=M;i++)
	{
		int node1 , node2;
		cin >> node1 >> node2;
		int node1P = findP(node1);
		int node2P = findP(node2);
		if(node1P == node2P)
		{
			ans =i;
			break;
		}
		P[node1P] = node2P;
	}
	cout << ans;	
} 