
#include <bits/stdc++.h>
using namespace std;
#define MAX 1001
#define INF 99999999
int cal(int cur)
{
	int result=0;
	for(int i=1;i<=cur;i++)
	{
		result+=i*i;
	}
	return result;
}
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	// 넣을 수 있는 구간의 수 : N+1
	// rest = N - (약속+1)*(약속 수) = 약속이 없는 날짜
	int N,M;
	cin >> N >> M;
	int arr[MAX];
	int total =0;
	for(int i=0;i<N;i++)
	{
		cin >> arr[i];
		total+=arr[i]+1;
	}
	int section = N+1;
	int rest = M-total;
	int restD = rest/section;
	int restR = rest%section;
	int ans=0;
	for(int i=0;i<section;i++)
	{
		if(i<restR) ans+=cal(restD+1);
		else ans+=cal(restD);
	}
	cout << ans;
}
