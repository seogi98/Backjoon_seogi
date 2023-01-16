#include<stdio.h>
#include<string>
#include<iostream>
#include<queue>

using namespace std;
int n, m;
int tx[4] = { 1,0,-1,0 };
int ty[4] = { 0,-1,0,1 }; int cnt = 0;
int map[100][100];
int temp[100][100];

queue<pair<int, int>> q;

string tmp;
void bfs(int i, int j)
{
	q.push(make_pair(i, j));
	map[i][j] = 0;
		while(!q.empty()){
		i = q.front().first;
		j = q.front().second;
		q.pop();
		for (int k = 0; k < 4; k++) {
			if (0 <= (i + ty[k]) && (i + ty[k]) < n){
				if (0 <= (j + tx[k]) && (j + tx[k]) < m){
					if (map[i + ty[k]][j + tx[k]]==1)
					{
						q.push(make_pair(i + ty[k], j + tx[k]));
						map[i + ty[k]][j + tx[k]] = map[i][j] + 1;
					}

				}
			}
		}
	}
}
int main(void)
{
	cin >> n;
	cin >> m;

	char a;
	int h = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		for (int j = 0; j < m; j++)
		{
			a = tmp[j];
			if (a == '1')
			{
				map[i][j] = 1;
			}
			else
			{
				map[i][j] = 0;
			}
		}
	}
	map[0][0] = 0;
	bfs(0,0);
	cout << map[n-1][m-1]+1;


}