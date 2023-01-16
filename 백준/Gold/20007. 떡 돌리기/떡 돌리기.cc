#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX 5010
#define INF 20999999999999
vector<pair<long long,long long>> E[MAX];
priority_queue<pair<long long,long long>> pq; // (dist,curNode)
priority_queue<pair<long long,long long>> mnpq; // (dist,node)
long long dist[MAX];
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	long long N,M,X,Y;
	// 집 , 도로 , 거리 , 성현이 집
	cin >> N >> M >> X >> Y;
	for(long long i=0;i<N;i++)
	{
		dist[i] = INF;
	}
	for(long long i=0;i<M;i++)
	{
		long long a,b,c;
		cin >> a >> b >> c;
		E[a].push_back({b,c});
		E[b].push_back({a,c});
	}
	dist[Y] = 0;
	pq.push({0,Y});
	while(!pq.empty())
	{
		long long cur = pq.top().second;
		long long curDist = -pq.top().first;
		pq.pop();
		for(long long i=0;i<E[cur].size();i++)
		{
			long long nxt = E[cur][i].first;
			long long nextDist = E[cur][i].second + curDist;
			if(nextDist < dist[nxt])
			{
				dist[nxt] = nextDist;
				pq.push({-nextDist,nxt});
			}
		}
	}
	sort(dist,dist+N);
	long long rest = X;
	long long ans=1;
	for(long long i=0;i<N;i++)
	{
		long long D = dist[i];
		if(X < D*2)
		{
			cout << -1;
			return 0;
		}
		if(rest < D*2)
		{
			ans++;
			rest = X;
		}
		rest -=2*D;
	}
	cout << ans;
}
