#include<bits/stdc++.h>
using namespace std;
#define MAX 101
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
struct Ga{
    int dst;
    int eat;
    int y;
    int x;
};
int R,C,T;
char mp[MAX][MAX];
bool vst[MAX][MAX];
int ans = 0;
void dfs(Ga cur){
    if(cur.dst >= T){
        ans = max(ans,cur.eat);
        return;
    }
    for(int i=0;i<4;i++){
        int nx = cur.x +dx[i];
        int ny = cur.y +dy[i];
        int nxEat = cur.eat;
        int nxDst = cur.dst+1;
        if(ny < 0 || ny >= R || nx < 0 || nx >= C) continue;
        if(mp[ny][nx] == '#') continue;
        if(mp[ny][nx] == 'S') {
            nxEat++;
            mp[ny][nx] = '.';
            dfs({nxDst,nxEat,ny,nx});
            mp[ny][nx] = 'S';
            continue;
        }
        dfs({nxDst,nxEat,ny,nx});
    }
}
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    pair<int,int> start;
    cin >> R >> C >> T;
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            cin >> mp[i][j];
            if(mp[i][j] == 'G'){
                start = {i,j};
                mp[i][j] = '.';
            }
        }
    }
    dfs({0,0,start.first,start.second});
    cout << ans;
}