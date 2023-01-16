#include<iostream>

using namespace std;

int minArr(int a,  int b)
{
	return a>b?b:a;
}
int main(void)
{
	int N;
	cin >>  N;
	
	int arr[1001][3];
	int DP[1001][3];
	for(int i=1;i<=N;i++)
	{
		for(int j=0;j<3;j++)
		{
			cin >> arr[i][j];
		}
	}
	
	DP[1][0]=arr[1][0];
	DP[1][1]=arr[1][1];
	DP[1][2]=arr[1][2];
	
	for(int i=2;i<=N;i++)
	{
		DP[i][0]=min(DP[i-1][1],DP[i-1][2])+arr[i][0];
		DP[i][1]=min(DP[i-1][0],DP[i-1][2])+arr[i][1];
		DP[i][2]=min(DP[i-1][0],DP[i-1][1])+arr[i][2];
	}
	cout<<minArr(minArr(DP[N][0],DP[N][1]),DP[N][2]);
}