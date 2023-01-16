#include<bits/stdc++.h>
using namespace std;
#define MAX 101
int mp[MAX][MAX];
int mpF[MAX][MAX];
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N,K;
	cin >> N >> K;
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=N;j++)
		{	
			int prex = (j-1)*K;
			int prey = (i-1)*K;
			int curx = j*K;
			int cury = i*K;
			int t;
			cin >> t;
			for(int q=prey;q<cury;q++)
			{
				for(int z=prex;z<curx;z++)
				{
					mpF[q][z] = t;
				}
			}
		}
	}
	for(int i=0;i<N*K;i++)
	{
		for(int j=0;j<N*K;j++)
		{
			cout << mpF[i][j] << " ";
		}
		cout << "\n";
	}
}