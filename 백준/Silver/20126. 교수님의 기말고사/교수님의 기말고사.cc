#include <bits/stdc++.h>
using namespace std;
#define MAX 1001
#define INF 99999999
vector<pair<int,int>> V;
// sort 후, 빈 시간 : cur.start - pre.start+pre.time
//main 함수
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N,M,S; // (횟수 , 시험시간 , 마지막)
	int ans=-1;
	cin >> N >> M >> S;
	for(int i=0;i<N;i++)
	{
		int start, tm;
		cin >> start >> tm;
		V.push_back({start,tm});
	}
	sort(V.begin(),V.end());
	V.push_back({S,0});
	pair<int,int> pre = {0,0};
	for(int i=0;i<V.size();i++)
	{
		pair<int,int> cur = V[i];
		int restT = cur.first - (pre.first+ pre.second);
		if(restT >= M)
		{
			ans = (pre.first+ pre.second);
			break;
		}
		pre = cur;
	}
	cout << ans;
}
