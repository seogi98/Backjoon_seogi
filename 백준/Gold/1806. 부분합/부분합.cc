#include <bits/stdc++.h>
using namespace std;
#define MAX 100010
#define INF 199999999
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N,S;
	cin >> N >> S;
	int arr[MAX];
	for(int i=0;i<N;i++)
	{
		cin >> arr[i];
	}
	int start = 0;
	int end =0;
	int sum=arr[0];
	int mn= INF;
	while(start<N)
	{
		if(sum>=S)
		{
			mn = min(mn,end-start+1);
			sum-=arr[start];
			start++;
			continue;
		}
		if(end == N) 
		{
			sum-=arr[start];
			start++;
			continue;
		}
		end++;
		sum+=arr[end];
	}
	if(mn == INF)
	{
		mn=0;
	}
	cout << mn;
}