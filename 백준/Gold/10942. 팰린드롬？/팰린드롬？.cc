#include<iostream>
#include<algorithm>
#include<string.h>
#include<vector>

using namespace std;

int Pl[2001];
bool DP[2001][2001];//[start][end]  
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    memset(DP,false,sizeof(DP));  
    int N;
    int T;
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> Pl[i];
        DP[i][i] = true;
    }
    for(int i=2;i<=N;i++)
    {
        if(Pl[i] == Pl[i-1])
        {
            DP[i-1][i]=true;
        }
    }
    for(int i=2;i<N;i++)
    {
        for(int j=1;j<=N-i;j++)
        {
            if(Pl[j] == Pl[j+i]&&DP[j+1][j+i-1])
            {
                DP[j][j+i] = true;
            }      
        }
    }
    cin >> T;
    for(int i=0;i<T;i++)
    {
        int C,D;
        cin >> C >> D;
        cout << DP[C][D]<<"\n";
    }
    

}


