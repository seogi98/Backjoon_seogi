#include <bits/stdc++.h>
using namespace std;
#define MAX 100001
#define INF 999999999999999

long long dst[MAX][2];
vector<pair<long long,long long>> E[MAX];
bool cmp(pair<long long,long long> p1,pair<long long,long long> p2)
{
	return p1.second < p2.second;
}
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	long long N,M;
	cin >> N >> M;
	for(long long i=1;i<=N;i++)
	{
		dst[i][0] = INF;
		dst[i][1] = INF;
	}
	for(long long i=1;i<=M;i++)
	{
		long long node1 ,node2 ,weight;
		cin >> node1 >> node2 >> weight;
		E[node1].push_back({node2, weight});
		E[node2].push_back({node1, weight});
	}
	for(long long i=1;i<=N;i++)
	{
		sort(E[i].begin(),E[i].end(),cmp);
	}
	//(-weight,node)
	priority_queue<pair<long long,long long>> pq;
	dst[1][0] = 0;
	pq.push({0,1});
	while(!pq.empty())
	{
		long long curD = -pq.top().first;
		long long curNode = pq.top().second;
		pq.pop();
		int evenOdd = curD%2;
		if(curD > dst[curNode][evenOdd])
		{
			continue;
		}
		for(long long i=0;i<E[curNode].size();i++)
		{
			long long nxNode = E[curNode][i].first;
			long long nxD = E[curNode][i].second + curD;
			// nxD 짝수 홀수 판단
			long long evenOdd = nxD%2;
			if(dst[nxNode][evenOdd] > nxD)
			{
				dst[nxNode][evenOdd] = nxD;
				pq.push({-nxD,nxNode});
			}
		}
	}
	for(long long i=1;i<=N;i++)
	{
		if(dst[i][0] >= INF)
		{
			dst[i][0] = -1;
		}
		if(dst[i][1] >= INF)
		{
			dst[i][1] = -1;
		}
		cout << dst[i][1] << " " << dst[i][0] << "\n";
	}
}
