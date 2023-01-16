// 백준 1865번
#include <bits/stdc++.h>
#define MAX 550
#define INF 19876543
using namespace std;
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); 
    int TC;
    cin >> TC;
    while(TC--)
    {
        int dst[MAX][MAX];
        int N,M,W;
        cin >> N >> M >> W;
        for(int i=0;i<=N;i++)
        {
            for(int j=0;j<=N;j++)
            {
                if(i==j){
                    dst[i][j] =0;
                    continue;
                }
                dst[i][j] = INF;
            }
        }
        for(int i=0;i<M;i++)
        {
            int S,E,T;
            cin >> S >> E >> T;
            dst[S][E] = min(T,dst[S][E]);
            dst[E][S] = min(T,dst[S][E]);
        }
        for(int i=0;i<W;i++)
        {
            int S,E,T;
            cin >> S >> E >> T;
            dst[S][E] = min(-T,dst[S][E]);
        }
        // 중간 노드
        for(int k=1;k<=N;k++)
        {
            // 시작 노드
            for(int i=1;i<=N;i++)
            {
                // 도착 노드
                for(int j=1;j<=N;j++)
                {
                    if(dst[i][j] > dst[i][k]+dst[k][j])
                    {
                        dst[i][j] = dst[i][k]+dst[k][j];
                    }
                }
            }
        }
        string Back = "NO\n";
        for(int i=1;i<=N;i++)
        {
            if(dst[i][i]<0)
            {
                Back = "YES\n";
                break;
            }
        }
        cout << Back;
    }

}