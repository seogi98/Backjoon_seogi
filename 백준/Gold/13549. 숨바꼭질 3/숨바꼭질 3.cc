#include <bits/stdc++.h>
#define MAX 100001
using namespace std;
int vst[MAX];
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	int ans=0;
	cin >> N >> M;
	priority_queue<pair<int,int>> pq; // (time,cur)
	for(int i=0;i<MAX;i++)
	{
		vst[i] = MAX;
	}
	pq.push({0,N});
	while(!pq.empty())
	{
		int cur = pq.top().second;
		int time = -pq.top().first;
		pq.pop();
		if(cur == M) break;
		int nx[3];
		nx[0] = cur*2;
		nx[1] = cur-1;
		nx[2] = cur+1;
		for(int i=0;i<3;i++)
		{
			// 범위 벗어나면 continue
			if(nx[i]<0 || nx[i]>MAX) continue;
			//순간이동
			if(i==0)
			{
				//더 빨리 방문한 노드일 경우 continue
				if(vst[nx[i]] <= time) continue;
				// 아니면 탐색
				vst[nx[i]] = time;
				pq.push({-time,nx[i]});
				continue;
			}
			// 이미 방문한 노드인 경우
			if(vst[nx[i]] <= time+1) continue;
			// 아니면 탐색
			vst[nx[i]] = time+1;
			pq.push({-(time+1),nx[i]});
		}
	}
	if(N==M)
	{
		cout << 0;
		return 0;
	}
	cout << vst[M];
}