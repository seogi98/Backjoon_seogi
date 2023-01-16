// 16236번 아기상어
/*
0: 빈 칸
1, 2, 3, 4, 5, 6: 칸에 있는 물고기의 크기
9: 아기 상어의 위치
*/
#include <bits/stdc++.h>
using namespace std;
#define MAX 21
#define INF 1999999999
int N;
int mp[MAX][MAX];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,-1,0,1};
int ans=0;
//거리가 가까운 물고기 찾기
// return 좌표값(y,x) , 이동거리 , input 물고기 size,시작 좌표
bool cmp(pair<int,int> p1,pair<int,int> p2)
{
    if(p1.first == p2.first)
        return p1.second < p2.second;
    return p1.first < p2.first;
}
pair<int,int> findF(int size,pair<int,int> start)
{
    bool vst[MAX][MAX];
    bool stop = false;
    memset(vst,false,sizeof(vst));
    //(y,x) , distance
    queue<pair<pair<int,int>,int>> q;
    vector<pair<int,int>> cd;
    q.push({start,0});
    vst[start.first][start.second] = true; 
    int stopD=INF;
    while(!q.empty())
    {
        pair<int,int> cur = q.front().first;
        int dis = q.front().second;
        q.pop();
        if(dis > stopD)
        {
            continue;
        }
        for(int i=0;i<4;i++)
        {
            int tx = cur.second+dx[i];
            int ty = cur.first+dy[i];
            if(ty<0 || ty>=N||tx <0 || tx>=N) continue;
            if(vst[ty][tx]) continue;
            if(mp[ty][tx]>size) continue;
            if(mp[ty][tx]<size && mp[ty][tx]!=0)
            {
                vst[ty][tx] = true;
                stopD = dis;
                cd.push_back({ty,tx});
                continue;
            }
            vst[ty][tx] = true;
            q.push({{ty,tx},dis+1});
            continue;

        }
    }
    if(cd.empty())
    {
        return {-1,-1};
    }
    sort(cd.begin(),cd.end(),cmp);
    mp[cd.front().first][cd.front().second] = 0;
    ans+=stopD+1;
    return cd.front();
}
int main()
{
    //ios::sync_with_stdio(false);
    //cin.tie(NULL);
    cin >> N;
    pair<int,int> st;
    int Fsize = 2;
    int Fexp = 0; 
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            cin >> mp[i][j];
            if(mp[i][j]== 9)
            {
                st.first = i;
                st.second = j;
                mp[i][j] =0;
            }
        }
    }
    while(1)
    {
        st = findF(Fsize,st);
        if(st.first == -1) break;
        Fexp ++;
        if(Fexp == Fsize) 
        {
            Fexp =0;
            Fsize++;
        }
    }
    cout << ans;
}