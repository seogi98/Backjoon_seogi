#include <bits/stdc++.h>
using namespace std;
#define MAX 200
#define INF 10000
vector<int> E[MAX];
int dst[MAX][MAX];
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N, M;
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if(i == j) continue;
			dst[i][j] = INF;
		}
	}
	for (int i = 0; i < M; i++)
	{
		int node1, node2;
		cin >> node1 >> node2;
		dst[node1][node2] = 1;
		dst[node2][node1] = 1;
	}
    //1. 거처가는 노드
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
	int mn = INF;
	int ans1 = -1;
	int ans2 = -1;
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){
			int node1 = i;
			int node2 = j;
			if(node1 >= node2) continue;
			int total = 0;
			for(int k=1;k<=N;k++){
				total+=min(dst[node1][k],dst[node2][k]);
			}
			if(total < mn){
				ans1 = node1;
				ans2 = node2;
				mn = total;
			}
		}
	}
	cout << ans1 << " " << ans2<< " " << mn*2;
}