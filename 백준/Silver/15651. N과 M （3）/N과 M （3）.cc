#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdlib.h>
#include <queue>
#include <vector>
using namespace std;


int N,M;
int arr[8];
void dfs(int n,int idx)
{
    arr[n] = idx;
    if(n==M)
    {
        for (int i = 1; i <= M; i++)
        {
            cout << arr[i]<< " ";
        }
        cout << "\n";
        return;
    }
    for(int i=1;i<=N;i++)
    {
        dfs(n+1,i);
    }
    return;
    
}
int main(void)
{

    cin >> N >> M;
    for (int i = 1; i <= N; i++)
    {
        dfs(1,i);
    }
    

}
