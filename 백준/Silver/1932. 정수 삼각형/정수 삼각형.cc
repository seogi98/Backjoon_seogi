#include<iostream>
#include<queue>
#include<functional>

using namespace std;

int minArr(int a,  int b)
{
	return a>b?b:a;
}

int maxArr(int a,  int b)
{
	return a<b?b:a;
}
int main(void)
{
	int N;
	int tri[1000][1000];
	int DP[1000][1000];
	priority_queue<int> pq;
	
	
	cin >> N;
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=i;j++)
		{
			cin >> tri[i][j];
		}
	}
	DP[1][1] = tri[1][1];
	
	for(int i=2;i<=N;i++)
	{
		for(int j=1;j<=i;j++)
		{
			if(j==1)
			{
				DP[i][j] = DP[i-1][j]+tri[i][j];	
			}
			else if(i==j)
			{
				DP[i][j] = DP[i-1][j-1]+tri[i][j];	
			}
			else{
				DP[i][j] = maxArr(DP[i-1][j-1],DP[i-1][j])+tri[i][j];
			}
			//cout <<"DP["<<i<<"]"<<"["<<j<<"]"<< DP[i][j]<< " ";
		}
		//cout << endl;
	}
	for(int i=1;i<=N;i++)
	{
		pq.push(DP[N][i]);
	}
	cout << pq.top();

}