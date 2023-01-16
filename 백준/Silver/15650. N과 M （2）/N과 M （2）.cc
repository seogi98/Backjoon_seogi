#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdlib.h>
#include <queue>
#include <vector>
using namespace std;


int N,M;
bool vst[10]={false,};
int arr[10];
int dfs(int n,int idx,vector<int> v)
{
    if(idx > N+1)
    {
        return 0;
    }
    if(n==M)
    {
        for(int i=0;i<M;i++)
        {
            cout << v[i] << " ";
        }
        cout << "\n";
        return 0;
    }
    v.push_back(idx);
    dfs(n+1,idx+1,v);
    v.pop_back();
    dfs(n,idx+1,v);
    return 0;
}
int main(void)
{
    vector<int> v;

    cin >> N >> M;
    dfs(0,1,v);

}
