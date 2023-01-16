#include <bits/stdc++.h>
using namespace std;
#define MAX 100
#define INF 99999999
// 다익스트라 , 지나온 거리중 최소 요금 거리 저장, vst처리 -> 우선순위큐 1. 최대요금 , 2. 거리 각각 가장 작은것 방문표시 처리

// 차로 개수 N, 골목 개수 M, 시작 교차로 번호 A, 도착 교차로 번호 B, 가진 돈 C 
int N,M,A,B,C;
vector<pair<int,int>> E[MAX];
//최대 요금, 최소 거리
pair<int,int> dst[MAX];

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M >> A >> B >> C;
	for(int j=0;j<=N;j++)
	{
		dst[j] = {INF,INF};
	}
	for(int i=0;i<M;i++)
	{
		int node1 , node2, weight;
		cin >> node1 >> node2 >> weight;
		E[node1].push_back({node2,weight});
		E[node2].push_back({node1,weight});
	}
	// 1. 최대요금
	// 2. 거리
	// 3. 다음노드
	priority_queue<pair<pair<int,int>,int>> pq;
	pq.push({{0,0},A});
	dst[1] = {0,0};
	while(!pq.empty())
	{
		int V = - pq.top().first.first;
		int D = - pq.top().first.second;
		int curNode = pq.top().second; 
		pq.pop();
		for(int i=0;i<E[curNode].size();i++)
		{
			int nxNode = E[curNode][i].first;
			// 다음 거리
			int nxDist = D + E[curNode][i].second;
			// 최소 비용
			int mn = max(V,E[curNode][i].second);
			// 거리가 부족할때
			if(nxDist > C)
			{
				continue;
			}
			// 최소 비용보다 작을때
			if((dst[nxNode].first > mn) || (dst[nxNode].first == mn && dst[nxNode].second > nxDist))
			{
				dst[nxNode] = {mn,nxDist};
				pq.push({{-mn,-nxDist},nxNode});
			}	
		}
	}
	if(dst[B].first == INF)
	{
		dst[B].first = -1;
	}
	cout << dst[B].first;
}
