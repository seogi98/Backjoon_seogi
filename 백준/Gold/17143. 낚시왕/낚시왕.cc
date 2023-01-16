#include <bits/stdc++.h>
using namespace std;
#define MAX 110
#define MMAX 10010
typedef long long ll;
ll dx[5] = {0, 0, 0, 1, -1};
ll dy[5] = {0, -1, 1, 0, 0};
ll R, C, M;
bool isDead[MMAX];
struct Shark
{
    ll y;
    ll x;
    ll speed;
    //d가 1인 경우는 위, 2인 경우는 아래, 3인 경우는 오른쪽, 4인 경우는 왼쪽을 의미한다.
    ll dir;
    ll size;
    bool isDead = false;
};
vector<vector<Shark>> mp(MAX, vector<Shark>(MAX, {0, 0, 0, 0, 0, 0}));
bool cmp(Shark s1, Shark s2)
{
    return s1.size > s2.size;
}
void seeM()
{

    cout << "\n";
    for (ll i = 1; i <= R; i++)
    {
        for (ll j = 1; j <= C; j++)
        {
            cout << mp[i][j].size << " ";
        }
        cout << "\n";
    }
}
int main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    // cout.tie(0);
    // 격자판의 크기 R, C와 상어의 수 M
    ll ans=0;
    cin >> R >> C >> M;
    // (r, c)는 상어의 위치, s는 속력, d는 이동 방향, z는 크기이다.
    vector<Shark> shark;
    for (ll i = 0; i < M; i++)
    {
        Shark tmp;
        cin >> tmp.y >> tmp.x >> tmp.speed >> tmp.dir >> tmp.size;
        // 반복되는 주기이다.
        ll rowRp = (R - 1) * 2;
        ll columnRp = (C - 1) * 2;
        // 위아래
        if (tmp.dir <= 2)
            tmp.speed = tmp.speed % rowRp;
        if (tmp.dir > 2)
            tmp.speed = tmp.speed % columnRp;
        mp[tmp.y][tmp.x] = tmp;
        shark.push_back(tmp);
    }
    for (ll fishman = 1; fishman <= C; fishman++)
    {
        //seeM();
        if(shark.empty()) break;
        // 가장 가까운 상어 낚는다.
        ll fishCaught = 0;
        for (ll i = 1; i <= R; i++)
        {
            if (mp[i][fishman].size > 0)
            {
                fishCaught = mp[i][fishman].size;
                ans +=mp[i][fishman].size;
                break;
            }
        }
        // 존제 여부
        vector<vector<bool>> ext(MAX,vector<bool>(MAX,false));
        // 상어가 다 움직인 후 옮겨준다.
        vector<Shark> sharkCur;
        // 상어 위치 저장
        vector<vector<Shark>> tmp(MAX, vector<Shark>(MAX, {0, 0, 0, 0, 0, 0}));
        for (ll i = 0; i < shark.size(); i++)
        {
            Shark cur = shark[i];
            if(isDead[cur.size]) continue;
            if (cur.size == fishCaught)
            {
                isDead[cur.size] = true;
                continue;
            }
            // 속력만큼 이동한다.
            for (ll j = 1; j <= cur.speed; j++)
            {
                // 다음 좌표
                cur.x = cur.x + dx[cur.dir];
                cur.y = cur.y + dy[cur.dir];
                // 만약에 좌표 밖으로 넘어 갈 경우 방향 바꿔줌
                if (cur.y <= 0 || cur.y > R || cur.x <= 0 || cur.x > C)
                {
                    if (cur.dir == 1)
                        cur.dir = 2;
                    else if (cur.dir == 2)
                        cur.dir = 1;
                    else if (cur.dir == 3)
                        cur.dir = 4;
                    else if (cur.dir == 4)
                        cur.dir = 3;
                    j-=2;
                }
            }
            // 만약에 상어가 있을경우
            if (ext[cur.y][cur.x])
            {
                // 크기가 작을경우 skip
                if (tmp[cur.y][cur.x].size > cur.size)
                    continue;
                // 클경우 그 자리에 있던 물고기 잡아먹음
                else
                {
                    isDead[tmp[cur.y][cur.x].size] = true;
                }
            }
            sharkCur.push_back(cur);
            tmp[cur.y][cur.x] = cur;
            ext[cur.y][cur.x] = true;
        }
        shark = sharkCur;
        mp = tmp;
    }
    cout << ans;
}