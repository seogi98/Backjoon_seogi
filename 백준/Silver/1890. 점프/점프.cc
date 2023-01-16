#include <iostream>
using namespace std;
 
int N;
int map[100][100]={0};
long dp[100][100]={0};
int visited[100][100]={0};
 
int dy[2]={1,0};
int dx[2]={0,1};
 
long dfs(int y,int x){
    
    if(y==N-1 && x==N-1){
        return 1;
    }
    
    if(map[y][x]==0)
        return 0;
    
    if(visited[y][x] || dp[y][x]){
        return dp[y][x];
    }
    
    visited[y][x]=1;
    for(int i=0;i<2;i++){
        int ny=y+dy[i]*map[y][x];
        int nx=x+dx[i]*map[y][x];
 
        
        if(ny>=N || nx>=N)
            continue;
        
        dp[y][x]+=dfs(ny,nx);
    }
    
    return dp[y][x];
}
int main(){
    
    cin>>N;
    
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin >> map[i][j];
        }
    }
    
    cout<<dfs(0,0)<<endl;
    return 0;
}
 