#include <bits/stdc++.h>
using namespace std;
#define MAX 21
#define INF 99999999
int N;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
bool outOfRange(int y,int x){
	if(y < 0 || y >= N || x < 0 || x >= N){
		return true;
	} 
	return false;
}
void seeM(vector<vector<int>> mp){
	cout << "\n";
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			cout <<  mp[i][j] << " ";
		}
		cout << "\n";
	}
}

vector<vector<int>> moveD(int dir,vector<vector<int>> mp){
	vector<vector<int>> delayArr(MAX,vector<int>(MAX,0));
	// 합쳐졌을경우 
	vector<vector<bool>> isBlocked(MAX,vector<bool>(MAX,false));
	// dir => 오 아래 왼 위
	if(dir == 0){
		for(int i=0;i<N;i++){
			for(int j=N-1;j>=0;j--)
			{
				//seeM(delayArr);
				// 현재 
				int cur = mp[i][j];
				int y = i + dy[dir];
				int x = j + dx[dir];
				while(!outOfRange(y,x)){
					if(isBlocked[y][x] || delayArr[y][x] != 0){break;}
					y+=dy[dir];
					x+=dx[dir];
				}
				y-=dy[dir];
				x-=dx[dir];
				int nx = x+dx[dir];
				int ny = y+dy[dir];
				// 범위 밖으로 나갈 경우 
				if(outOfRange(ny,nx) || isBlocked[ny][nx]){
					delayArr[y][x] = cur;
					continue;
				}
				// 합쳐질경우
				if(delayArr[ny][nx] == cur){
					isBlocked[ny][nx] = true;
					delayArr[ny][nx]*=2;
					continue;
				}
				// 움직이지 않았을 경우
				if(j == x && i == y) {
					delayArr[i][j] = cur;
					continue;
				}
				delayArr[y][x] = cur;
			}
		}
	}	if(dir == 1){
		for(int j=0;j<N;j++){
			for(int i=N-1;i>=0;i--)
			{
				//seeM(delayArr);
				// 현재 
				int cur = mp[i][j];
				int y = i + dy[dir];
				int x = j + dx[dir];
				while(!outOfRange(y,x)){
					if(isBlocked[y][x] || delayArr[y][x] != 0){break;}
					y+=dy[dir];
					x+=dx[dir];
				}
				y-=dy[dir];
				x-=dx[dir];
				int nx = x+dx[dir];
				int ny = y+dy[dir];
				// 범위 밖으로 나갈 경우 
				if(outOfRange(ny,nx) || isBlocked[ny][nx]){
					delayArr[y][x] = cur;
					continue;
				}
				// 합쳐질경우
				if(delayArr[ny][nx] == cur){
					isBlocked[ny][nx] = true;
					delayArr[ny][nx]*=2;
					continue;
				}
				// 움직이지 않았을 경우
				if(j == x && i == y) {
					delayArr[i][j] = cur;
					continue;
				}
				delayArr[y][x] = cur;
			}
		}
	}	if(dir == 2){
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++)
			{
				//seeM(delayArr);
				// 현재 
				int cur = mp[i][j];
				int y = i + dy[dir];
				int x = j + dx[dir];
				while(!outOfRange(y,x)){
					if(isBlocked[y][x] || delayArr[y][x] != 0){break;}
					y+=dy[dir];
					x+=dx[dir];
				}
				y-=dy[dir];
				x-=dx[dir];
				int nx = x+dx[dir];
				int ny = y+dy[dir];
				// 범위 밖으로 나갈 경우 
				if(outOfRange(ny,nx) || isBlocked[ny][nx]){
					delayArr[y][x] = cur;
					continue;
				}
				// 합쳐질경우
				if(delayArr[ny][nx] == cur){
					isBlocked[ny][nx] = true;
					delayArr[ny][nx]*=2;
					continue;
				}
				// 움직이지 않았을 경우
				if(j == x && i == y) {
					delayArr[i][j] = cur;
					continue;
				}
				delayArr[y][x] = cur;
			}
		}
	}	if(dir == 3){
		for(int j=0;j<N;j++){
			for(int i=0;i<N;i++)
			{
				//seeM(delayArr);
				// 현재 
				int cur = mp[i][j];
				int y = i + dy[dir];
				int x = j + dx[dir];
				while(!outOfRange(y,x)){
					if(isBlocked[y][x] || delayArr[y][x] != 0){break;}
					y+=dy[dir];
					x+=dx[dir];
				}
				y-=dy[dir];
				x-=dx[dir];
				int nx = x+dx[dir];
				int ny = y+dy[dir];
				// 범위 밖으로 나갈 경우 
				if(outOfRange(ny,nx) || isBlocked[ny][nx]){
					delayArr[y][x] = cur;
					continue;
				}
				// 합쳐질경우
				if(delayArr[ny][nx] == cur){
					isBlocked[ny][nx] = true;
					delayArr[ny][nx]*=2;
					continue;
				}
				// 움직이지 않았을 경우
				if(j == x && i == y) {
					delayArr[i][j] = cur;
					continue;
				}
				delayArr[y][x] = cur;
			}
		}
	}
	
	return delayArr;
}
int checkLargeNum(vector<vector<int>> mp){
	int mx = 0;
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			mx = max(mx,mp[i][j]);
		}
	}
	return mx;
}
int dfs(int dir,int n,vector<vector<int>> cur){
	int mx = 0;
	if(n == 5){
		return checkLargeNum(cur);
	}
	for(int i=0;i<4;i++){
		mx = max(dfs(i,n+1,moveD(i,cur)),mx);
	}
	return mx;
}
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int ans = 0;
	cin >> N;
	vector<vector<int>> mp(MAX,vector<int>(MAX,0));
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			cin >> mp[i][j];
		}
	}
	//cout << N;
	cout << dfs(0,0,mp);
	//seeM(moveD(2,mp));

}
