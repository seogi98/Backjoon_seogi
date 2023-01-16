#include <bits/stdc++.h>
#define MAX 100001
using namespace std;
typedef long long ll;
ll P[MAX];
ll unionFind(ll cur)
{
	if(cur == P[cur]) return cur;
	return P[cur] = unionFind(P[cur]);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	// 첫 번째 줄에는 통신탑의 개수인 자연수 N, 통신탑 사이의 연결의 개수인 자연수 M, 통신망 연결 분할 횟수인 자연수 Q가 공백으로 구분되어 주어진다.
	// 거꾸로 올라가면서 노드를 합친다.
	ll N,M,Q;
	cin >> N >> M >> Q;
	pair<ll,ll> E[MAX];
	// 노드 개수
	ll nodeCount[MAX];
	for(ll i=1;i<=N;i++)
	{
		nodeCount[i] = 1;
		P[i] = i;
	}
	// 일단 간선들 저장
	for(ll i=1;i<=M;i++)
	{
		ll node1 , node2;
		cin >> node1 >> node2;
		E[i]= {node1,node2};
	}
	// 제거하는 노드들 저장
	vector<ll> rm;
	bool ext[MAX];
	memset(ext,false,sizeof(ext));
	for(ll i=0;i<Q;i++)
	{
		ll t;
		cin >> t;
		rm.push_back(t);
		ext[t] = true;
	}
	// 일단 제거하지 않는 간선들 부터 합친다.
	for(ll i=1;i<=M;i++)
	{
		// 존재하면 skip
		if(ext[i]) continue;
		ll node1 = E[i].first;
		ll node2 = E[i].second;
		ll node1P = unionFind(node1);
		ll node2P = unionFind(node2);
		// 다르면 개수를 더해준다.
		if(node1P != node2P)
		{
			nodeCount[node1P] += nodeCount[node2P];
			nodeCount[node2P] = 0;
			P[node2P] = node1P;
		}
	}
	ll answer = 0;
	// 제거하는 간선들을 합친다.
	for(ll i=rm.size()-1;i>=0;i--)
	{
		ll node1 = E[rm[i]].first;
		ll node2 = E[rm[i]].second;
		ll node1P = unionFind(node1);
		ll node2P = unionFind(node2);
		if(node1P != node2P)
		{
			answer += nodeCount[node1P]*nodeCount[node2P];
			nodeCount[node1P] += nodeCount[node2P];
			nodeCount[node2P] = 0;
			P[node2P] = node1P;
		}
	}
	cout << answer;
}
