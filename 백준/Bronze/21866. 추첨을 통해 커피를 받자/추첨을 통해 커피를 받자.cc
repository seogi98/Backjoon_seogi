#include<bits/stdc++.h>
using namespace std;
#define MAX 100000
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	//100점, 100점, 200점, 200점, 300점, 300점, 400점, 400점, 500점
	vector<int> score = {100,100,200,200,300,300,400,400,500};
	int total =0;
	string ans = "draw";
	for(int i=0;i<9;i++)
	{
		int sc;
		cin >> sc;
		total += sc;
		if(score[i] < sc){
			ans = "hacker";
		}
	}
	if(total <100) ans = "none";
	cout << ans;
}