#include<iostream>
#include<queue>
#include<string.h>

using namespace std;
//투 포인트 알고리즘
//부분합을 구하면서 부분합보다 데이터가 크면 end++ 작으면  start++한다.

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N,M;
	cin >> N >> M;
	int V[10001];
	for(int i=0;i<N;i++)
	{
		cin >> V[i];
	}
	int start=0,end =0;
	int cur =0;
	int result=0;
	while(1)
	{
		if(cur >=M) cur-=V[start++];
		else if(end >= N) break;
		else cur+=V[end++];
		if(cur == M) result++;
		
	}
	cout << result;

}