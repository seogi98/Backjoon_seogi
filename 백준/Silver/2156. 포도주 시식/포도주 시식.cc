#include<iostream>
#include<queue>
#include<functional>
#include<algorithm>
using namespace std;

int main(void)
{
 	int GP[10001];
 	int DP[10001];
 	int N;
 	
 	cin >> N;
	for(int i=1;i<=N;i++)
	{
		cin >>GP[i];
	}
	DP[1] = GP[1]; // 6
	DP[2] = GP[1]+GP[2]; // 16
	DP[3] = max(max(GP[1],GP[2])+GP[3],DP[2]);// 23
	
	for(int i=4;i<=N;i++)
	{		
	 		DP[i] = max(DP[i-2],GP[i-1]+DP[i-3])+GP[i];
	 		DP[i] = max(DP[i-1],DP[i]);
	}
	for(int i=1;i<=N;i++)
	{
	 	//	cout <<"DP["<<i<<"]"<< DP[i]<<endl;
	}
	
	sort(DP+1,DP+N+1);
	cout << DP[N];
	
}