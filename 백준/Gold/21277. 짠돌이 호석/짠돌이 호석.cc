#include<bits/stdc++.h>
using namespace std;
#define INF 1000000
#define MAX 200
#define MID 100
#define MMID 50
int n1,m1;
int n2,m2;
bool pz1[MAX][MAX];
bool pz2[MAX][MAX][4]; // 시계방향
struct P{
	int y;
	int x;
};
bool isdup(int dir,P start){
	int y = start.y;
	int x = start.x;
	for(int i=y;i<y+n2;i++){
		for(int j=x;j<x+m2;j++){
			if(pz2[i-y][j-x][dir]&&pz1[i][j]){
				return false;
			}
		}
	}
	return true;
}
// 넓이 반환
int getArea()
{
	int mn = INF;	
	for(int i=MID-MMID;i<=MID+MMID;i++)
	{
		for(int j=MID-MMID;j<=MID+MMID;j++)
		{
			P start = {i,j};
			P end = {i+n2,j+m2};
			for(int k=0;k<4;k++){
				if(!isdup(k,start)) continue;
				int xMn = min(j,MID);
				int yMn = min(i,MID);
				int xMx = max(m1+MID,end.x);
				int yMx = max(n1+MID,end.y);
				int area = (yMx - yMn) * (xMx - xMn);
				mn = min(mn,area);
			}
		}
	}
	return mn;
}
void printA(int dir){
	cout << "\n";
	for(int i=0;i<5;i++){
		for(int j=0;j<5;j++){
			cout << pz2[i][j][dir];
		}
		cout << "\n";
	}
}
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n1 >> m1;
	// 퍼즐을 중앙에 놓는다.
	for(int i=MID;i<n1+MID;i++){
		for(int j=MID;j<m1+MID;j++){
			char tmp;
			cin >> tmp;
			if(tmp == '1'){
				pz1[i][j] = true;
			}
		}
	}
	cin >> n2 >> m2;
	for(int i=0;i<n2;i++)
	{
		for(int j=0;j<m2;j++){
			char tmp;
			cin >> tmp;
			if(tmp == '1'){
				pz2[i][j][0] = pz2[n2-1-i][m2-1-j][1] = pz2[j][i][2] = pz2[m2-1-j][n2-1-i][3] = true;
			}
		}
	}
	cout << getArea();
}