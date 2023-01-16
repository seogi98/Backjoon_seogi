#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX 100010
ll dp[MAX];
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int H,Y;
	cin >> H >> Y;
	dp[0]=H;
	for(int i=1;i<=Y;i++)
	{
		ll A=0,B=0,C=0;
		A = dp[i-1]*1.05;
		dp[i] = A;
		if(i<3) continue;
		B = dp[i-3]*1.2;
		dp[i] = max(dp[i],B);
		if(i<5) continue;
 		C = dp[i-5]*1.35;
		dp[i] = max(dp[i],C);
	}
	cout << dp[Y];
}