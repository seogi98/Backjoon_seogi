#include <bits/stdc++.h>
using namespace std;
#define MAX 2001

int cal[MAX][MAX];
bool cmp(pair<int,int> p1,pair<int,int> p2)
{
	if(p1.first == p2.first)
	{
		return p1.second > p2.second;
	}
	return p1.first < p2.first;
}
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	int ans=0;
	cin >> N;
	vector<pair<int,int>> V;
	for(int i=0;i<N;i++)
	{
		int node1,  node2;
		cin >> node1 >> node2;
		V.push_back({node1,node2});
	}
	sort(V.begin(),V.end(),cmp);
	//가장 앞
	int front = V.front().first;
	//가장 뒤
	int back = V.front().second;

	//front > back 일경우 mx =0;
	int mx =0;
	V.push_back({500,500});
	for(int i=0;i<V.size();i++)
	{
		// 시작
		int b = V[i].first;
		// 끝
		int e = V[i].second;
		if(back+1 < b)
		{
			ans +=(back-front+1)*mx;
			mx=0;
			front = b;
			back = e;
		}
		back = max(e,back);
		int P;
		for(int j=1;j<=MAX;j++)
		{
			if(cal[b][j] == 0)
			{
			  	P = j;
				mx = max(P,mx);
				break;
			}
		}
		for(int j=b;j<=e;j++)
		{
			cal[j][P] = 1;
		}

	}
	cout << ans;
}