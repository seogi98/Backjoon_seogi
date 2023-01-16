#include <bits/stdc++.h>
#define MAX 100
using namespace std;
vector<pair<int, int>> E[MAX];
int item[MAX];     //
int dst[MAX][MAX]; //시작점 , 노드
#define INF 98765432
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N, M, R;
    //지역의 개수 , 수색범위 , 길의 개수
    cin >> N >> M >> R;
    for (int i = 1; i <= N; i++)
    {
        cin >> item[i];
        for (int j = 1; j <= N; j++)
        {
            if (i == j)
                continue;
            dst[i][j] = INF;
        }
    }
    for (int i = 0; i < R; i++)
    {
        int node1, node2, weight;
        cin >> node1 >> node2 >> weight;
        dst[node1][node2] = weight;
        dst[node2][node1] = weight;
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
    int mx = 0;
    for (int i = 1; i <= N; i++)
    {
        //시작노드
        int start = i;
        int sum = 0;
        for (int j = 1; j <= N; j++)
        {
            if (dst[i][j] <= M)
            {
                sum += item[j];
            }
        }
        mx = max(sum, mx);
    }
    cout << mx;
}