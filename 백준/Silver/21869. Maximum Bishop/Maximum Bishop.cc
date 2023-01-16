#include<bits/stdc++.h>
using namespace std;
#define MAX 100000
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin >> N;
	if(N==1){
		cout << 1 << '\n';
		cout << 1 << " " << 1;
		return 0;
	}
	cout << N+N-2 << "\n";
	for(int i=1;i<=N;i++){
		cout << 1 << " " << i << "\n";
	}
	for(int i=2;i<=N-1;i++){
		cout << N << " " << i << "\n";
	}
}
