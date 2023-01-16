#include<iostream>
#include<queue>
#include<functional>

using namespace std;
int main(void)
{
	int DP[101][10];
	int N;
	long long total=0;
	cin >> N;
	DP[1][0]=0;
	for(int i=1;i<=9;i++)
	{
		DP[1][i]=1;
	}
	for(int i=2;i<=N;i++)
	{
		for(int j=0;j<=9;j++)
		{
			if(j==0)
			{
				DP[i][j] = DP[i-1][j+1];		
			}
			else if(j==9)
			{
				DP[i][j] = DP[i-1][j-1];		
			}
			else
			{
				DP[i][j] = (DP[i-1][j-1]+DP[i-1][j+1])%1000000000;	
			}
		}
	}
	for(int i=0;i<=9;i++)
	{
		total+=DP[N][i];
		total=total%1000000000;
	}
	cout << (total%1000000000);
	
	
}