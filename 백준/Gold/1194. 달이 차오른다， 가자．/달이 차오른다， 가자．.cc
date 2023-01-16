#include <bits/stdc++.h>
using namespace std;
#define MAX 51
#define INF 1000000
char mp[MAX][MAX];
int dst[MAX][MAX][200];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
struct MS
{
    int y;
    int x;
    int key;
    int d;
};
struct cmp
{
    bool operator()(MS m1, MS m2)
    {
        return m1.d > m2.d;
    }
};
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N, M;
    cin >> N >> M;
    MS cur;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> mp[i][j];
            for (int k = 0; k <= 200; k++)
            {
                dst[i][j][k] = INF;
            }
            if (mp[i][j] == '0')
            {
                cur = {i, j, 0, 0};
            }
        }
    }
    priority_queue<MS, vector<MS>, cmp> pq;
    pq.push(cur);
    int ans = -1;
    while (!pq.empty())
    {
        MS cur = pq.top();
        int y = cur.y;
        int x = cur.x;
        int key = cur.key;
        int d = cur.d;
        pq.pop();
        if(mp[y][x] == '1'){
            ans = d;
            break;
        }
        if (dst[y][x][key] < d)
            continue;
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            char nc = mp[ny][nx];
            int nk = key;
            int nd = d+1;
            // 갈 수 없는 지역인 경우
            if(nc == '#' || nx < 0 || nx >=M || ny <0 || ny>=N) continue;

            // 열쇠 획득
            if('a'<= nc && nc <= 'f'){
                nk |= 2 << nc-'a';
            }
            // 문
            if('A'<= nc && nc <= 'F') {
                // 열쇠를 가지고 있지 않을 경우
                int tmp = 2<< nc-'A';
                if((tmp&key) != tmp)
                {
                    continue;
                }
            }
            if(dst[ny][nx][nk] <= nd){
                continue;
            }
            dst[ny][nx][nk] = nd;
            pq.push({ny,nx,nk,nd});
        }
    }
    cout << ans;
}