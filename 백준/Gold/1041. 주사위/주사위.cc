#include<bits/stdc++.h>
using namespace std;
#define MAX 500100
vector<long long> dice;
int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	long long N;
	cin >> N;
	long long mn[4] = {MAX,MAX,MAX,MAX};
	long long mx = 0;
	long long sum=0;
	for(long long i=0;i<6;i++){
		long long tmp;
		cin >> tmp;
		dice.push_back(tmp);
		mn[1] =  min(mn[1],tmp);
		mx = max(tmp,mx);
		sum +=tmp;
	}
	for(int i=0;i<6;i++){
		for(int j=i+1;j<6;j++){
			if(i==0 && j == 5) continue;
			if(i==1 && j == 4) continue;
			if(i==2 && j == 3) continue;
			mn[2] = min(mn[2],dice[i]+dice[j]);
		}
	}
	mn[3] = min(mn[3],dice[0]+dice[1]+dice[2]);
	mn[3] = min(mn[3],dice[0]+dice[1]+dice[3]);
	mn[3] = min(mn[3],dice[0]+dice[3]+dice[4]);
	mn[3] = min(mn[3],dice[0]+dice[2]+dice[4]);
	mn[3] = min(mn[3],dice[5]+dice[1]+dice[2]);
	mn[3] = min(mn[3],dice[5]+dice[1]+dice[3]);
	mn[3] = min(mn[3],dice[5]+dice[3]+dice[4]);
	mn[3] = min(mn[3],dice[5]+dice[2]+dice[4]);
	
	// 면 하나
	long long tmp1 = ((N-2)*(N-2)*5+(N-2)*4)*mn[1];
	// 면 두개
	long long tmp2 = ((N-2)*8+4)*mn[2];
	// 면 세개
	long long tmp3 = 4*mn[3];
	long long ans = tmp1+tmp2+tmp3;
	if(N==1){
		ans = sum-mx;
	}
	cout << ans;

}