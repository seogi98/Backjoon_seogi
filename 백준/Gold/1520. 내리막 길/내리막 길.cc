#include <iostream>
#include <algorithm>
#include <string.h>
#include<queue>

using namespace std;

int N,M;
int dp[501][501];
int map[501][501];
int vst[501][501]={-1,};
int cannotFind[501][501]={0,};
int dfs(int x,int y)
{
    int tx,ty;
    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,-1,0,1};
    int check=0;
    
    if(vst[y][x]!=-1)
    {
        return vst[y][x];
    }
    if(x==0&&y==0)
    {
        return 1;
    }
    vst[y][x] =0;
    for(int i=0;i<4;i++)
    {
        tx = x+dx[i];
        ty = y+dy[i];
        if(tx<M&&ty<N&&tx>=0&&ty>=0)
        {
            if(map[y][x]<map[ty][tx])
            {
                vst[y][x] += dfs(tx,ty);
                //cout << "vst["<<y<<"]"<<"["<<x<<"] : "<<vst[y][x]<<endl;
            }
            else
            {
                check++;
            }
        }
    }
    if(check==4)
    {
         vst[y][x] == -1;
         return 0;
    }
    return vst[y][x];
}
int main(void)
{
    cin >> N >> M;
    memset(vst,-1,sizeof(vst));
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        
        {
            cin >> map[i][j];
        }
    }
    
    cout << dfs(M-1,N-1)<<endl;
    //for(int i=0;i<N;i++)
    {
        //for(int j=0;j<M;j++)
        {
            //cout << vst[i][j]<< " ";
        }
        //cout << endl;
    }
}
