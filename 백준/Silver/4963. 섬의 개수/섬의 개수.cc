#include <string>
#include <math.h>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <string.h>
#define MAX 4000
#define INF 10000001
using namespace std;
//첫번쨰로 
int dx[8] = {1,1,0,-1,-1,-1,0,1};
int dy[8] = {0,-1,-1,-1,0,1,1,1};
bool vst[51][51];
int map[51][51];
int N,M;
void dfs(pair<int,int> p)
{
    vst[p.first][p.second]=true;
    for(int i=0;i<8;i++)
    {
        int nx = p.second+dx[i];
        int ny = p.first+dy[i];
        if(nx>=0&&nx<M&&ny>=0&&ny<N)
        {
            if(!vst[ny][nx]&&map[ny][nx]==1)
            {
                dfs({ny,nx});
            }
        }
    }
}
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    while(1)
    {
        int result=0;
        cin >> M >> N;
        if(N==0&M==0)
        {
            break;
        }
        memset(vst,false,sizeof(vst));
        memset(map,0,sizeof(map));
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<M;j++)
            {
                cin >> map[i][j];
            }
        }
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<M;j++)
            {
                if(map[i][j] == 1&&!vst[i][j])
                {
                    dfs({i,j});
                    result+=1;
                }
            }
        }
        cout << result<<"\n";
        

    }
}
