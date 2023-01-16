// 백준 1865번
// 1. 치즈위치 다 저장
// 2. 전체 치즈 돌면서 2변 만나는거 저장
// 3. 치즈로 둘러쌓인 부분 찾는다
// 4. 저장된 치즈 한꺼번에 처리
// 반복
#include <bits/stdc++.h>
#define MAX 101
#define INF 98765432
using namespace std;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int N, M;
struct cheese
{
    int Y;
    int X;
    bool isMelt;
};
// 전체 치즈
vector<cheese> ch;
// 녹을 치즈
vector<cheese> melt;
int mp[MAX][MAX];
// 겉의 공기를 2으로 만든다.
void makeOut2()
{
    queue<pair<int,int>> q;
    q.push({0,0});
    while(!q.empty())
    {
        int x = q.front().second;
        int y = q.front().first;
        q.pop();
        for(int i=0;i<4;i++)
        {
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(ny <0 || ny >= N || nx <0 || nx>=M) continue;
            if(mp[ny][nx] >=1) continue;
            mp[ny][nx] = 2;
            q.push({ny,nx});
        }
    }  
}
// 겉의 공기를 0으로 만든다.
void makeOut0()
{
    queue<pair<int,int>> q;
    q.push({0,0});
    int vst[MAX][MAX];
    memset(vst,false,sizeof(vst));
    while(!q.empty())
    {
        int x = q.front().second;
        int y = q.front().first;
        q.pop();
        for(int i=0;i<4;i++)
        {
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(ny <0 || ny >= N || nx <0 || nx>=M) continue;
            if(mp[ny][nx] ==1) continue;
            if(vst[ny][nx]) continue;
            mp[ny][nx] = 0;
            vst[ny][nx] = true;
            q.push({ny,nx});
        }
    }
    
}
bool findMeltCheese()
{
    //만약에 녹는 치즈가 없다면 true반환
    bool notMelt = true;
    for (int i = 0; i < ch.size(); i++)
    {
        if (ch[i].isMelt)
            continue;
        notMelt = false;
        int y = ch[i].Y;
        int x = ch[i].X;
        int oxygenN = 0;
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            //0,1이면 치즈, 내부
            if (mp[ny][nx]<=1)
                continue;
            oxygenN++;
        }
        if (oxygenN >= 2)
        {
            ch[i].isMelt = true;
            melt.push_back(ch[i]);
        }
    }
    return notMelt;
}

void meltingCheese()
{
    for (int i = 0; i < melt.size(); i++)
    {
        int y = melt[i].Y;
        int x = melt[i].X;
        mp[y][x] = 0;
    }
    //다 녹였으면 초기화 시켜준다.
    melt.clear();
}

void seeM()
{

    cout << "\n";
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cout << mp[i][j] << " ";
        }
        cout << "\n";
    }

    cout << "\n";
}
int main(void)
{
    //ios::sync_with_stdio(false);
    //cin.tie(NULL);
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> mp[i][j];
            if (mp[i][j])
            {
                ch.push_back({i, j, false}); // (Y,X)
            }
        }
    }
    int ans = 0;
    while (1)
    {
        //seeM();
        //겉에 2로 만들고
        makeOut2();
        if (findMeltCheese())
            break;
        makeOut0();
        meltingCheese();
        ans++;
    }
    cout << ans;
}