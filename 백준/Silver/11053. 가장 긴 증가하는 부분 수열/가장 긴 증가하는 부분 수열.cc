#include<iostream>
#include<queue>
#include<functional>
#include<algorithm>
using namespace std;

int main(void)
{
	int N;
	int arr[1001];
	int DP[1001]={0,};
	
	cin >> N;
	for(int i=1;i<=N;i++)
	{
		cin >> arr[i];
	}
	
	for(int i=1;i<=N;i++)
	{
		int min=0;
		for(int j=1;j<=i;j++)
		{
			if(arr[i]>arr[j])
			{
				if(min < DP[j])
				{
	   			 	   min = DP[j];
				}
			}
		}
		DP[i] = min+1;
		//cout << i << " : " << DP[i] << endl;
	}
	sort(DP+1,DP+N+1);
	cout << DP[N];
	
	
}
