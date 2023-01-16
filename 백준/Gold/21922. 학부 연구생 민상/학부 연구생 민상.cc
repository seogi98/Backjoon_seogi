#include<bits/stdc++.h>
using namespace std;
#define MAX 2001
// 방향
int vst[MAX][MAX][4];
int mp[MAX][MAX];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,-1,0,1};
struct wind{
    int y;
    int x;
    int dir;
};
int convertDir(int dir,int stuff){
    int result = dir;
    if(stuff == 1){
        if(dir == 0) result = 2;
        if(dir == 2) result = 0;
    }
    if(stuff == 2){
        if(dir == 1) result = 3;
        if(dir == 3) result = 1;
    }
    if(stuff == 3){
        if(dir == 0) result = 1;
        if(dir == 1) result = 0;       
        if(dir == 2) result = 3;
        if(dir == 3) result = 2;
    }
    if(stuff == 4){
        if(dir == 0) result = 3;
        if(dir == 1) result = 2;       
        if(dir == 2) result = 1;
        if(dir == 3) result = 0;
    }
    return result;
}

    // tmp
    bool tmp[MAX][MAX];
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N,M;
    cin >> N >> M;
    vector<pair<int,int>> air;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin >> mp[i][j];
            // 에어컨
            if(mp[i][j] == 9){
                air.push_back({i,j});
            }
        }
    }
    for(auto start : air){
        queue<wind> q;
        for(int i=0;i<4;i++){
            if(vst[start.first][start.second][i]) continue;
            q.push({start.first,start.second,i});
            vst[start.first][start.second][i] = true;
        }
        while(!q.empty()){
            wind cur = q.front();
            int y = cur.y;
            int x = cur.x;
            int nextDir = convertDir(cur.dir,mp[y][x]);
            int ny = cur.y+dy[nextDir];
            int nx = cur.x+dx[nextDir];
            q.pop();
            // 범위 밖
            if(ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
            if(vst[ny][nx][nextDir]) continue;
            vst[ny][nx][nextDir] = true;
            q.push({ny,nx,nextDir});
        }
    }
    int answer =0;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            bool check  = false;
            for(int k=0;k<4;k++){
                if(vst[i][j][k]){
                    check = true;
                }
            }
            if(check) {
                tmp[i][j] = true;
                answer++;
            }
        }
    }
    cout << answer << "\n";
    // for(int i=0;i<N;i++){
    //     for(int j=0;j<M;j++){
    //         cout << tmp[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
}