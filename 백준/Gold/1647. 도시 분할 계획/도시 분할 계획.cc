#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX 100010
#define INF 2147483610000000
long long dist[MAX];
vector<pair<long long, long long>> E[MAX];
priority_queue<pair<long long, pair<long long, long long>>> pq; // (dist,start,end)

long long P[MAX];
//1. mst
long long ufind(long long curNode)
{
	if (P[curNode] == curNode)
	{
		return curNode;
	}
	return P[curNode] = ufind(P[curNode]);
}
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	long long N, K;
	cin >> N >> K;
	for (long long i = 1; i <= N; i++)
	{
		P[i] = i;
	}
	for (long long i = 0; i < K; i++)
	{
		long long a, b, c;
		cin >> a >> b >> c;
		pq.push({-c, {a, b}});
	}
	long long sum = 0;
	long long pre = 0;

	while (!pq.empty())
	{
		long long node1, node2, dist;
		node1 = pq.top().second.first;
		node2 = pq.top().second.second;
		dist = -pq.top().first;
		pq.pop();
		long long node1P = ufind(node1);
		long long node2P = ufind(node2);
		if (node1P == node2P) continue;
		P[node1P] = node2P; //merge
		pre = dist;
		sum += dist;
	}
    cout << sum - pre;
}