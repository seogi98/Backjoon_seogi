
#include<iostream>
#include<queue>
#include<vector>

#include<algorithm>

using namespace std;


int len;
int main()
{
    int dx[4] = {1,0,-1,0};//가로
    int dy[4] = {0,-1,0,1};//세로

    int bfs[50][50];
    int T;//테스트케이스
    cin >> T;
    for(int p=0;p<T;p++)
    {
        queue<pair<int,int>> q;
        int map[50][50]={0,};
        int M,N;//가로 세로
        int X,Y;//X는 가로 Y는 세로
        int A,B;//q.front()
        int tmX,tmY;
        int K;
        int result=0;
        cin >> N >> M >> K;
        for(int i=0;i<K;i++)
        {
            cin >> X >> Y;
            map[Y][X]=1;
            //bfs[Y][X]=1;
        }
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<M;j++)
            {
                if(map[j][i]==1)
                {
                    q.push(make_pair(j,i));
                    while(!q.empty())
                    {
                        A = q.front().first;//가로
                        B = q.front().second;//세로
                        q.pop();

                        for(int k=0;k<4;k++)
                        {
                            tmX = A+dx[k];
                            tmY = B+dy[k];
                            if(tmX <M&&tmX>=0&&tmY<N&&tmY>=0)
                            {
                                if(map[tmX][tmY]==1){
                                    q.push(make_pair(tmX,tmY));
                                    map[tmX][tmY] = 0;
                                }
                            }
                        }
                    }
                    result ++;
                    //cout << "X : " << j <<"Y : " <<i <<endl;
                }
            }
        }
        cout << result<<endl;
    }

}