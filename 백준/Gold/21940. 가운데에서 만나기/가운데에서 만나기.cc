#include <bits/stdc++.h>
#define MAX 201
#define INF 1LL << 32
using namespace std;
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	long long N, M;
	cin >> N >> M;
	vector<vector<long long>> dst(MAX, vector<long long>(MAX, INF));
	for (long long i = 1; i <= N; i++)
	{
		dst[i][i] = 0;
	}
	for (long long i = 0; i < M; i++)
	{
		long long node1, node2, w;
		cin >> node1 >> node2 >> w;
		dst[node1][node2] = w;
	}
    for (int k = 1; k <= N; k++)
    {
        //2. 시작 노드
        for (int i = 1; i <= N; i++)
        {
            //3. 도착 노드
            for (int j = 1; j <= N; j++)
            {
                // 중간에 거처가는게 더 빠르다면
                if (dst[i][k] + dst[k][j] < dst[i][j])
                {
                    //노드를 갱신한다.
                    dst[i][j] = dst[i][k] + dst[k][j];
                }
            }
        }
    }
	long long K;
	long long liveIn[MAX];
	cin >> K;
	for (long long i = 0; i < K; i++)
	{
		cin >> liveIn[i];
	}
	vector<long long> ans;
	long long mn = INF;
	for (long long i = 1; i <= N; i++)
	{
		long long mx = 0;
		for (long long j = 0; j < K; j++)
		{
			long long start = liveIn[j];
			mx = max(dst[start][i] + dst[i][start], mx);
		}
		if (mn >= mx)
		{
			if (mn > mx)
			{
				ans.clear();
			}
			mn = mx;
			ans.push_back(i);
			continue;
		}
	}
	for (auto i : ans)
	{
		cout << i << " ";
	}
}