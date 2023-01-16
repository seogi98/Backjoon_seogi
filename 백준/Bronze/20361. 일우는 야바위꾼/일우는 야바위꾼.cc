#include<bits/stdc++.h>
using namespace std;
#define MAX 200000
int arr[MAX];

void swap(int *s1,int *s2)
{
	int tmp = *s1;
	*s1 = *s2;
	*s2 = tmp;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N,X,K;
	cin >> N >> X >> K;
	arr[X] = 1;
	int ans = -1;
	for(int i=0;i<K;i++)
	{
		int node1 , node2;
		cin >> node1 >> node2;
		swap(arr+node1,arr+node2);
	}
	for(int i=1;i<=N;i++)
	{
		if(arr[i] == 1)
		{
			ans = i;
			break;
		}
	}
	cout << ans;
	
}