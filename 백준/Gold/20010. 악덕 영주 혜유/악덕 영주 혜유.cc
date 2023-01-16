#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX 5010
#define INF 2147483610000000
long long dist[MAX];
vector<pair<long long, long long>> E[MAX];
priority_queue<pair<long long, pair<long long, long long>>> pq; // (dist,start,end)
priority_queue<pair<long long, long long>> pq2;

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
	for (long long i = 0; i < N; i++)
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
	while (!pq.empty())
	{
		long long node1, node2, dist;
		node1 = pq.top().second.first;
		node2 = pq.top().second.second;
		dist = -pq.top().first;
		pq.pop();
		long long node1P = ufind(node1);
		long long node2P = ufind(node2);
		if (node1P == node2P)
		{
			continue;
		}
		P[node1P] = node2P; //merge
		E[node1].push_back({node2, dist});
		E[node2].push_back({node1, dist});
		sum += dist;
	}
	cout << sum << "\n";
	//mst 1 end

	//2-1 dijkstra check longer polong long
	for (long long i = 0; i < N; i++)
	{
		dist[i] = INF;
	}
	dist[0] = 0;
	pq2.push({0, 0});
	while (!pq2.empty())
	{
		long long cur = pq2.top().second;
		long long curDist = -pq2.top().first;
		pq2.pop();
		for (long long i = 0; i < E[cur].size(); i++)
		{
			long long nxt = E[cur][i].first;
			long long nextDist = E[cur][i].second + curDist;
			if (nextDist < dist[nxt])
			{
				dist[nxt] = nextDist;
				pq2.push({-nextDist, nxt});
			}
		}
	}
	long long mx = 0;
	long long lp = 0;
	for (long long i = 0; i < N; i++)
	{
		if (mx < dist[i])
		{
			lp = i;
			mx = dist[i];
		}
	}
	//2-2 dijkstra check polong long to polong long distance
	long long mmx=0;
	for (long long i = 0; i < N; i++)
	{
		dist[i] = INF;
	}
	dist[lp] = 0;
	pq2.push({0, lp});
	while (!pq2.empty())
	{
		long long cur = pq2.top().second;
		long long curDist = -pq2.top().first;
		pq2.pop();
		for (long long i = 0; i < E[cur].size(); i++)
		{
			long long nxt = E[cur][i].first;
			long long nextDist = E[cur][i].second + curDist;
			if (nextDist < dist[nxt])
			{
				dist[nxt] = nextDist;
				mmx = max(nextDist,mmx);
				pq2.push({-nextDist, nxt});
			}
		}
	}
	cout << mmx;

}