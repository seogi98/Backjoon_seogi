#include <bits/stdc++.h>
using namespace std;
#define MAX 100000
#define INF 999999999
struct cmp1
{
	bool operator()(pair<int, int> p1, pair<int, int> p2)
	{
		if (p1.first == p2.first)
			return p1.second > p2.second;
		return p1.first > p2.first;
	}
};
bool cmp2(pair<int, int> p1, pair<int, int> p2)
{
	if (p1.second == p2.second)
		return p1.first < p2.first;
	return p1.second < p2.second;
};
bool isInclude(pair<int, int> p1, pair<int, int> p2)
{
	if (p1.first <= p2.first && p2.second <= p1.second)
	{
		return true;
	}
	return false;
}
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin >> N;
	vector<pair<int, int>> V;
	priority_queue<pair<int, int>, vector<pair<int, int>>, cmp1> pq;
	int mn = INF;
	for (int i = 0; i < N; i++)
	{
		int s, e;
		cin >> s >> e;
		mn = min(max(s, e), mn);
		V.push_back({min(s, e), max(s, e)});
	}
	sort(V.begin(), V.end(), cmp2);
	int d;
	cin >> d;
	pair<int, int> D = {mn-d, mn};
	int mx = 0;
	for (int i = 0; i < V.size(); i++)
	{
		pair<int, int> cur = V[i];
		if (cur.second - cur.first > d)
			continue;
		// 만약에 범위에 포함되지 않을 경우 포함될때 까지 D의 위치를 pq의 front로 옮겨야 한다.
		if(!isInclude(D, cur))
		{
			D.second = cur.second;
			D.first = D.second - d;
			if (pq.empty())
			{
				continue;
			}
			pair<int, int> tmp = pq.top();
			while(!isInclude(D,pq.top()))
			{
				if(pq.empty()) break;
				pq.pop();
				continue;
			}
		}
		pq.push(cur);
		mx = max(mx, (int)pq.size());
	}
	cout << mx;
}