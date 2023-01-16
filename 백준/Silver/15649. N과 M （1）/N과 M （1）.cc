#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdlib.h>
#include <queue>
#include <vector>

using namespace std;

vector<pair<int,string>> v;

int N,M;
bool vst[10]={false,};
int arr[10];
int dfs(int n)
{
    if(n==M)
    {
        for(int i=0;i<M;i++)
        {
            cout << arr[i] << " ";
        }
        cout << "\n";
        return 0;
    }
    for (int i = 1; i <= N; i++)
    {        
        if(!vst[i])
        {
            vst[i]=true;
            arr[n]=i;
            dfs(n+1);
            vst[i]=false;
            
        }
    }
    return 0;
    
}
int main(void)
{
    cin >> N >> M;
    dfs(0);
}