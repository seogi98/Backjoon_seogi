#include <bits/stdc++.h>
using namespace std;
#define MAX 10 ^ 10
#define INF 1987654321
typedef long long ll;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N, M;
	cin >> N >> M;
	vector<int> A;
	vector<int> B;
	vector<int> result;
	for (int i = 0; i < N; i++)
	{
		int T;
		cin >> T;
		A.push_back(T);
	}
	for (int i = 0; i < M; i++)
	{
		int T;
		cin >> T;
		B.push_back(T);
	}
	int ap = 0;
	int bp = 0;
	while(1)
	{
		if(ap==N&&bp==M)
		{
			break;
		}
		if(ap==N)
		{
			result.push_back(B[bp]);
			bp++;
			continue;
		}
		if(bp==M)
		{
			result.push_back(A[ap]);
			ap++;
			continue;
		}
		if(A[ap]>B[bp])
		{
			result.push_back(B[bp]);
			bp++;
			continue;
		}
		result.push_back(A[ap]);
		ap++;
	}
	for(int i=0;i<result.size();i++)
	{
		cout << result[i] << " ";
	}
}
