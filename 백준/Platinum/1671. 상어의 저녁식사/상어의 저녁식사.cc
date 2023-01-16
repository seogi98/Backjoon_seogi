#include <bits/stdc++.h>
using namespace std;
#define MAX 51
#define INF 1999999999
long long c[MAX*3][MAX*3]; // c[i][j]: i에서 j로 가는 간선의 용량
long long f[MAX*3][MAX*3]; // f[i][j]: i에서 j로 현재 흐르는 유량
vector<long long> E[MAX*3];
struct shark{
	long long a;
	long long b;
	long long c;
};
bool cmp(shark s1 , shark s2){
	if(s1.a >= s2.a && s1.b >= s2.b  && s1.c >= s2.c){
		return true;
	}
	return false;
}
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	long long N;
	long long M;
	cin >> N;
	long long s, e;
	s = 0;
	e = MAX+MAX+1;
	vector<shark> V;
	V.push_back({0,0,0});
	for (long long i = 1; i <= N; i++)
	{
		long long a,b,c;
		cin >> a >> b >> c;
		V.push_back({a,b,c});
	}
	for(long long i=1;i<=N;i++)
	{
		E[s].push_back(i);
		E[i].push_back(s);
		c[s][i] +=2;
		E[i+MAX].push_back(e);
		E[e].push_back(i+MAX);
		c[i+MAX][e]+=1;
		for(long long j=1;j<=N;j++)
		{
			if(i==j) continue;
			if(V[i].a == V[j].a && V[i].b == V[j].b && V[i].c == V[j].c && i>j) continue;
			if(cmp(V[i],V[j])){
				long long nx = j+MAX;
				E[i].push_back(nx);
				E[nx].push_back(i);
				c[i][nx] +=1;
			}
		}
	}
	long long total = 0;
	while (1)
	{
		// 방문 여부
		long long prev[MAX*3];
		fill(prev, prev + 3*MAX, -1);
		queue<long long> q;
		q.push(s);
		while (!q.empty() && prev[e] == -1)
		{
			long long cur = q.front();
			q.pop();
			for (auto nx : E[cur])
			{
				// c[i][j]-f[i][j] > 0: i에서 j로 유량을 흘릴 여유가 남았는가?
				// prev[next] == -1: next 정점을 아직 방문하지 않았는가?
				
				if (c[cur][nx] - f[cur][nx] > 0 && prev[nx] == -1)
				{
					q.push(nx);
					prev[nx] = cur;
					// 마지막 노드
					if (nx == e)
						break;
				}
			}
		}
		if (prev[e] == -1)
			break;
		long long flow = INF;
		// 경로상에서 가장 허용치가 낮은 곳을 찾음
		for (long long i = e; i != s; i = prev[i])
		{
			long long pre = prev[i];
			flow = min(flow, c[pre][i] - f[pre][i]);
		}
		// 찾은 flow만큼 해당 경로에 유량을 흘려줌
		for (long long i = e; i != s; i = prev[i])
		{
			long long pre = prev[i];
			f[pre][i] += flow;
			f[i][pre] -= flow;
		}
		total += flow;
	}
	cout << N-total;
}