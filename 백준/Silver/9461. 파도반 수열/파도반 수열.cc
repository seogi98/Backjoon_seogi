#include <iostream>
#include<string.h>
using namespace std;

int main () {

	int T;
    int N;
    
    cin >> T;
    while(T--)
    {
		cin >> N;
		long long dp[N+1]={0,};
        dp[0] = 1;
    	dp[1] = 1;
    	dp[2] = 1;
		for (int i = 3; i <= N; i++ ) dp[i] = (dp[i-2] + dp[i-3]);
		cout << dp[N-1]<<endl;
	}
    return 0;
}