#include<iostream>
#include<stack>
#include<algorithm>
#include<string>

using namespace std;
int map[25][25];
int n;
int q, w;
int num=0;
int tx[4] = { 1,0,-1,0 };
int ty[4] = { 0,-1,0,1 };
int temp[10000];
string tmp;
bool find_start() {
	int count=0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (map[i][j] == 1){
				q = i;
				w = j;
				return true;
			}
		}
	}
		return false;
}
void dfs(int i,int j)
{
	map[i][j]++;
	num++;
	for (int k = 0; k < 4; k++) {
		if (0 <= (i + ty[k]) && (i+ ty[k]) < n)
			if (0 <= (j + tx[k]) && (j + tx[k]) < n)
			{
				if (map[i+ty[k]][j+tx[k]] == 1)
				{
					dfs(i+ty[k],j+tx[k]);
				}
			}
		}
}
int main() {
	scanf("%d",&n);
	
	int h = 0;
	char a;

	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		for (int j = 0; j < n; j++)
		{
			a = tmp[j] ;
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
	while(find_start())
	{
		dfs(q,w);
		temp[h] = num;
		num = 0;
		h++;
	}
	sort(temp, temp + h);
	printf("%d\n", h);
	for (int i = 0; i < h; i++) {
		printf("%d\n", temp[i]);
	}
}