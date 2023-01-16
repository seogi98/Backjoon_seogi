#include <bits/stdc++.h>
using namespace std;
#define MAX 1025
#define INF 10000000001
typedef long long ll;
int N, M;
int A[MAX][MAX];
int bit[MAX][MAX];
//update
void update(int y, int x, int value)
{
    //세로
    while (y <= N)
    {
        //가로
        int j = x;
        while (j <= N)
        {
            //마지막 자리 숫자만큼 더한다. => 전체합으로 접근
            bit[y][j] += value;
            j += (j & -j);
        }
        y += (y & -y);
    }
}
int sum(int y, int x)
{
    int s = 0; // 총합
    //세로
    while (y > 0)
    {
        int j = x;
        //가로
        while (j > 0)
        {
            //마지막 자리 숫자만큼 뺀다.
            s += bit[y][j];
            j -= (j & -j);
        }
        y -= (y & -y);
    }
    return s;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            int T;
            cin >> T;
            A[i][j] = T;
            update(i, j, T);
        }
    }
    for (int i = 0; i < M; i++)
    {
        int Q;
        cin >> Q;
        if (Q == 0)
        {
            int x,y,c;
            cin >> y >> x >> c;
            update(y,x,c-A[y][x]);
            A[y][x] = c;
            continue;
        }
        int x1,y1,x2,y2;
        cin >> y1 >> x1 >>y2 >> x2;
        cout << sum(y2,x2)-sum(y2,x1-1)-sum(y1-1,x2)+sum(y1-1,x1-1)<<"\n";
    }
}