#include <bits/stdc++.h>
using namespace std;
vector<pair<long long, long long>> J;
vector<long long> B;
// weight가 가장 작은 순위부터 탐색
// curW > curjw 중에서 가장 value가 높은 보석을 반환한다.
priority_queue<pair<long long, long long>> pq; // (value,weight)
#define INF 987654321
bool cmp(pair<long long, long long> p1, pair<long long, long long> p2)
{
	return p1.first < p2.first;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	long long N, K;
	long long ans = 0;
	cin >> N >> K;
	for (long long i = 0; i < N; i++)
	{
		long long m, v;
		cin >> m >> v;
		J.push_back({m, v});
	}
	for (long long i = 0; i < K; i++)
	{
		long long c;
		cin >> c;
		B.push_back(c);
	}
	sort(B.begin(), B.end());
	sort(J.begin(), J.end(), cmp);
	long long jp = 0;
	for (long long i = 0; i < B.size(); i++)
	{
		long long bw = B[i];
		while (J[jp].first <= bw && jp < J.size())
		{	
			//value의 최대값을 뽑아야 하므로 반대로 집어넣어야한다.
			pq.push({J[jp].second, J[jp].first});
			jp++;
		}
		if (!pq.empty())
		{
			//그중 가장 작은값 추출 후 뽑아낸 보석 삭제
			ans += pq.top().first;
			pq.pop();
		}
	}
	cout << ans;
}
