#include <iostream>
#include <algorithm>
#include <string.h>
#include <queue>
#include <vector>

using namespace std;

int N,S;
int C[101];
int mx = 0;


/*void dfs(int n,int idx,int result)
{
    if(idx == N)
    {
        return;
    }
    if(result > S)
    {
        return;
    }
    if(n == 3)
    {
        if(result == S)
        {
            cout << result;
            exit(0);
        }
        if(result > mx)
        {
            mx = result;
        }
    }
    dfs(n+1,idx+1,result+C[idx]);
    dfs(n,idx+1,result);
}*/
int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> S;
    for (int i = 0; i < N; i++)
    {
        cin >> C[i];
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = i+1; j < N; j++)
        {
            for (int k = j+1; k < N; k++)
            {
                int result = C[i]+C[j]+C[k];
                if(result > mx && result <=S)
                {
                    mx = result;
                }
            }
            
        }
    }  
    cout << mx;
}