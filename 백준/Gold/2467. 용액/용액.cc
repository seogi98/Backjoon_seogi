#include <iostream>
#include <queue>
#include <string.h>
#include <math.h>
using namespace std;
//투 포인트 알고리즘
//부분합을 구하면서 부분합보다 데이터가 크면 end++ 작으면  start++한다.

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
	vector<int> V;
	for (int i = 0; i < N; i++)
	{
		int T;
		cin >> T;
		V.push_back(T);
	}
	int i = 0; //start
	int j = N - 1;
	int total = 2e9;
	pair<int, int> result;
	while (i < j)
	{
		int start = V[i];
		int end = V[j];
		if (abs(start + end) < total)
		{
			total = abs(start + end);
			result.first = V[i];
			result.second = V[j];
		}
		if (start + end < 0)
		{
			i++; // start ++
		}
		else
		{
			j--; // end ++
		}
	}
	cout << result.first << " " << result.second << "\n";
}