#include<iostream>
#include<algorithm>
#include<stdlib.h>
#include<queue>
#include<vector>
#include<string.h>

using namespace std;



int N;
int K;

int DP[101][100001];//[현재 index][남은 가방의 무게]
vector<pair<int,int>> v;

//DP[i][j] = max(DP[i][j+1],DP[i-W[i]][j-1]+v[j]);
int main(void)
{
    cin >> N >> K;
    for(int i=0;i<N;i++)
    {
        int A,B;
        cin >> A >> B;
        v.push_back({A,B});
    }
    memset(DP,0,sizeof(DP));
    for(int i=0;i<N;i++)//index
    {
        for (int j = 0; j <= K; j++)//남은 가방의 무게
        {
            if(i==0)
            {
                if(v[i].first<=j)
                {
                    DP[i][j] = v[i].second;
                }
                continue;
                
            }
            if(v[i].first<=j)
            {
                DP[i][j] =max(DP[i-1][j],DP[i-1][j-v[i].first]+v[i].second);
            }
            else
            {
                DP[i][j] = DP[i-1][j];
            }
            
        }
    }
    cout << DP[N-1][K];
}