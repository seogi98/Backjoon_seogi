#include<bits/stdc++.h>
using namespace std;
#define MAX 11
struct tree
{
    int Y;
    int X;
    int age;
};
int dx[8] = {1,1,0,-1,-1,-1,0,1};
int dy[8] = {0,1,1,1,0,-1,-1,-1};
int mp[MAX][MAX];
//겨울마다 추가되는 양분
int A[MAX][MAX];
//같은 위치에 중복되는 나무가 있으면 중복 표시를 한다.
int Tage[MAX][MAX];
deque<int> dp[MAX][MAX];
queue<tree> die;
queue<tree> spread;
int N,M,K;
void spring()
{
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=N;j++)
		{
            int size = dp[i][j].size();
            for(int z=0;z<size;z++)
            {
                //나이가 어린 나무 부터
			    int fr = dp[i][j].front();
                dp[i][j].pop_front();
                //양분을 못먹으면 die
                if(mp[i][j] - fr < 0)
			    {
                    die.push({i,j,(fr)});
                    continue;
			    }
                // 양분을 먹을 수 있으면
                mp[i][j] -=fr;
                fr++;
                //만약에 5의 배수일 경우
                if((fr%5)==0)
                {
                    spread.push({i,j,fr});
                }
                dp[i][j].push_back(fr);
            }
		}
	}
}
void summer()
{
    while(!die.empty())
    {
        tree cur = die.front();
        die.pop();
        mp[cur.Y][cur.X] += cur.age/2;
    }
}
void autumn()
{
    while(!spread.empty())
    {
        int y = spread.front().Y;
        int x = spread.front().X;
        spread.pop();
        for(int i=0;i<8;i++)
        {
            int ny = y+dy[i];
            int nx = x+dx[i];
            if(ny <= 0 || ny >N || nx <=0 || nx >N) continue;
            dp[ny][nx].push_front(1);
        }
    }
}
void winter()
{
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=N;j++)
        {
            mp[i][j]+= A[i][j];
        }
    }
}
int countTree()
{
    int ans=0;
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=N;j++)
        {
            ans+=dp[i][j].size();
        }
    }
    return ans;
}
int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> N >> M >> K;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
			mp[i][j] = 5;
            cin >> A[i][j];
        }
    }
    for (int i = 0; i < M; i++)
    {
		int x,y,z;
        cin >> x >> y >> z;
		dp[x][y].push_front(z);
    }
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            sort(dp[i][j].begin(),dp[i][j].end());
        }
    }
    for (int i = 0; i < K; i++)
    {
        //cout << i + 1 << "년도";
        //cout << "봄";
        spring();
        //seeMap();
        //cout << "여름";
        summer();
        //seeMap();
        //cout << "가을";
        autumn();
        //seeMap();
        //cout << "겨울";
        winter();
        //seeMap();
    }
    cout << countTree();
}