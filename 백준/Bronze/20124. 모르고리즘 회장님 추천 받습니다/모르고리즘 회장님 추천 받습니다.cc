#include <bits/stdc++.h>
using namespace std;
#define MAX 1001
#define INF 99999999
vector<pair<int,string>> V;
//main 함수
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
	for(int i=0;i<N;i++)
	{
		string name;
		int score;
		cin >> name >> score;
		V.push_back({-score,name});
	}
	sort(V.begin(),V.end());
	cout << V.front().second;
}
