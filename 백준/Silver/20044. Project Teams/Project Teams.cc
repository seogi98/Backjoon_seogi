// 백준 20044번 Project Teams
#include <bits/stdc++.h>
using namespace std;
#define MAX 1001
#define INF 987654321
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin >> N;
	vector<int> arr;
	priority_queue<int> pq;
	for(int i=0;i<N*2;i++)
	{
		int t;
		cin >> t;
		arr.push_back(t);
	}
	sort(arr.begin(),arr.end());
	for(int i=0;i<N;i++)
	{
		pq.push(-(arr[i]+arr[2*N-1-i]));
	}
	cout << -pq.top();
}