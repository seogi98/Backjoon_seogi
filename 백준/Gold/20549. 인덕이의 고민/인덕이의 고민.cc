#include <bits/stdc++.h>
using namespace std;
#define MAX 51
#define INF 1000000
struct Ori
{
    int Y;
    int X;
    // 과부화 수
    int over;
    // 먹은 먹이
    int eat = 0;
};
struct cmp
{
    bool operator()(Ori p1, Ori p2)
    {
        return p1.over > p2.over;
    }
};
// 나이트
int nxK[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int nyK[8] = {-2, -1, 1, 2, 2, 1, -1, -2};

// 비숍
int nxB[4] = {1, 1, -1, -1};
int nyB[4] = {-1, 1, 1, -1};
// 룩
int nxR[4] = {1, 0, -1, 0};
int nyR[4] = {0, 1, 0, -1};

int vst[MAX][MAX][100];

// 1이면 먹이
int mp[MAX][MAX];
int K, B, R;
int M;
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    // 나이트 , 비숍 , 룩
    cin >> K >> B >> R;
    int y, x;
    cin >> y >> x;
    Ori start = {y, x, 0};
    cin >> M;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            for (int k = 0; k <= 100; k++)
            {
                vst[i][j][k] = INF;
            }
        }
    }
    for (int i = 0; i < M; i++)
    {
        int y, x;
        cin >> y >> x;
        mp[y][x] = pow(2, i);
    }
    priority_queue<Ori, vector<Ori>, cmp> pq;
    pq.push(start);
    int ans = 0;
    while (!pq.empty())
    {
        Ori cur = pq.top();
        pq.pop();
        if (cur.eat == pow(2, M) - 1)
        {
            ans = cur.over;
            break;
        }
        if(vst[cur.Y][cur.X][cur.eat] < cur.over) continue;
        // 먹은 먹이수
        int eat = cur.eat;
        // 나이트
        for (int i = 0; i < 8; i++)
        {
            int ny = cur.Y + nyK[i];
            int nx = cur.X + nxK[i];
            if (nx < 0 || nx >= N || ny < 0 || ny >= N)
                continue;
            int nxEat = mp[ny][nx] != 0 ? eat | mp[ny][nx] : eat;
            int nOver = cur.over + K;
            // 이미 방문한 노드
            if (vst[ny][nx][nxEat] <= nOver)
            {
                continue;
            }
            vst[ny][nx][nxEat] = nOver;
            pq.push({ny, nx, nOver, nxEat});
        }

        // 비숍
        for (int i = 1; i <= N; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                int ny = cur.Y + nyB[j] * i;
                int nx = cur.X + nxB[j] * i;
                if (nx < 0 || nx >= N || ny < 0 || ny >= N)
                    continue;
                int nxEat = mp[ny][nx] != 0 ? eat | mp[ny][nx] : eat;
                int nOver = cur.over + B;
                if (vst[ny][nx][nxEat] <= nOver)
                {
                    continue;
                }
                vst[ny][nx][nxEat] = nOver;
                pq.push({ny, nx, nOver, nxEat});
            }
        }

        // 룩
        for (int i = 1; i <= N; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                int ny = cur.Y + nyR[j] * i;
                int nx = cur.X + nxR[j] * i;
                if (nx < 0 || nx >= N || ny < 0 || ny >= N)
                    continue;
                int nxEat = mp[ny][nx] != 0 ? eat | mp[ny][nx] : eat;
                int nOver = cur.over + R;
                if (vst[ny][nx][nxEat] <= nOver)
                {
                    continue;
                }
                vst[ny][nx][nxEat] = nOver;
                pq.push({ny, nx, nOver, nxEat});
            }
        }
    }
    cout << ans;
}