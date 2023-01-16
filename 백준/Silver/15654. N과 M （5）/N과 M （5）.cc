#include <bits/stdc++.h>
using namespace std;
#define MAX 1001
#define INF 987654321
vector<int> arr;
vector<vector<int>> ans;
int N, M;
int fact(int cur)
{
	if(cur == 0)
	{
		return 1;
	}
	return cur*fact(cur-1);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		int t;
		cin >> t;
		arr.push_back(t);
	}
	sort(arr.begin(), arr.end());
	int cur = 1;
	int dup =fact(N - M);
	do
	{
		if (cur == dup)
		{
			for (int i = 0; i < M; i++)
			{
				cout << arr[i] << " ";
			}
			cout << "\n";
			cur =1;
			continue;
		}
		cur++;
	} while (next_permutation(arr.begin(), arr.end()));
}