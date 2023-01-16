
#include<iostream>
#include<queue>
#include<vector>

#include<algorithm>

using namespace std;


int len;
int main()
{
    int N;
    int L;
    int a,b;
    int cnt=0;
    int map[101][101]={0,};
    int vst[101]={0,};

    queue<int> Q;
    cin >> N;
    cin >> L;
    for(int i=1;i<=L;i++)
    {
        cin >> a >> b;
        map[a][b]=1;
        map[b][a]=1;
    }
    Q.push(1);
    while(!Q.empty())
    {
        int st = Q.front();
        vst[st]=1;
        Q.pop();
        for(int i=1;i<=N;i++)
        {
            if(map[st][i]==1&&vst[i]!=1)
            {
                Q.push(i);
            }
        }
    }
    for(int i=2;i<=N;i++)
    {
        if(vst[i]==1)
        {
            cnt++;
            //cout<<i<<endl;
        }
    }
    cout<<cnt;
}