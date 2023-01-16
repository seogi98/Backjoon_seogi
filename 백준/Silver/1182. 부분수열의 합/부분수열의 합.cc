#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N,S;
int arr[21];
int ans=0;
void dfs(int idx1,int result)
{
    if(idx1 == N)
    {
        //cout <<endl;
        return;
    }
    //cout << arr[idx1] << ", ";
    if(result+arr[idx1] == S)
    {  
        ans++;
    }
    dfs(idx1+1,result);
    dfs(idx1+1,result+arr[idx1]);
}
int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> N >> S;
    for(int i=0;i<N;i++)
    {
        cin  >> arr[i];
    }
    dfs(0,0);
    cout <<ans;
}