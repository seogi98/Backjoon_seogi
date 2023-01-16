#include"WAEP.h"

void init(int T)
{
}

int janken(int P)
{
	int ans =0;
	// 보
	if(P == 0){
		ans = 0;
	}
	// 가위
	if(P == 2){
		ans = 2;
	}
	// 주먹
	if(P == 5){
		ans = 5;
	}
	return ans;
}