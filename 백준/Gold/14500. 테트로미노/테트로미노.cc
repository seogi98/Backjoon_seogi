#include <string>
#include <math.h>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <string.h>
#include <vector>

#define div 1000000003;
using namespace std;

int N, M;
int map[501][501];
bool vst[501][501];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};
int mx = 0;
bool cmp(int a,int b)
{
    return a>b;
}
void dfs(int n, int result, pair<int, int> p) //(y,x)
{
    vst[p.first][p.second]=true;
    if (n > 4)
    {
        mx = max(mx, result);
        //cout << result <<endl;
        return;
    }
    //cout << "(" << p.first <<","<< p.second << ") ";
    result += map[p.first][p.second];
    //ㅏ 모양
    if (n == 2)
    {
        vector<int> val;
        for (int i = 0; i < 4; i++)
        {
            int tx = p.second + dx[i];
            int ty = p.first + dy[i];
            if (!vst[ty][tx])
            {
                val.push_back(map[ty][tx]);
            }
        }
        if(val.size()>=2)
        {
            sort(val.begin(),val.end(),cmp);   
            mx = max(result+val[0]+val[1],mx);
            //cout << mx << " ";
        }
    }
    for (int i = 0; i < 4; i++)
    {
        int tx = p.second + dx[i];
        int ty = p.first + dy[i];
        if (tx >= 0 && tx < M && ty >= 0 && ty < N)
        {
            if (!vst[ty][tx])
            {
                vst[ty][tx] = true;
                dfs(n + 1, result, {ty, tx});
                vst[ty][tx] = false;
            }
        }
    }
    vst[p.first][p.second]=false;
}
int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> map[i][j];
            vst[i][j] = false;
        }
    }
    memset(vst,false,sizeof(vst));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            dfs(1, 0, {i, j});
        }
    }
    cout << mx;
}