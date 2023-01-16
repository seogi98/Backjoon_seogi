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
	int arr[500];
	int DP[500];
	cin >> N;

	for(int i=1;i<=N;i++)
	{
		cin >> arr[i];
			
	}
	
	DP[1]=arr[1];
	DP[2]=arr[1]+arr[2];
	DP[3]=max(arr[1],arr[2])+arr[3];
	
	for(int i=4;i<=N;i++)
	{
		DP[i] = max(DP[i-3]+arr[i-1],DP[i-2])+arr[i];
		//cout<<"DP["<<i<<"]"<<DP[i]<<endl;
	}
	cout << DP[N];
		
}