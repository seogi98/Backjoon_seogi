#include <bits/stdc++.h>
#define MAX 1000001
using namespace std;

int cal(int cur, int n)
{
	if (n == 0)
		return cur / 2;
	if (n == 1)
		return cur / 3;
	if (n == 2)
		return cur + 1;
	if (n == 3)
		return cur - 1;
	return 0;
}
int main()
{
	int T;
	cin >> T;
	vector<int> ans;
	while (T--)
	{
		bool decI[MAX];
		bool vst[MAX];
		memset(decI,false,sizeof(decI));
		memset(vst,false,sizeof(vst));
		for (int i = 2; i <= MAX; i++)
		{
			if (decI[i] == true)
			{
				continue;
			}
			for (int j = i * 2; j <= MAX; j += i)
			{
				decI[j] = true;
			}
		}
		int start, node1, node2;
		cin >> start >> node1 >> node2;
		// 횟수 , 현제 숫자
		queue<pair<int, int>> q;
		q.push({0, start});
		vst[start] = true;
		bool isIn = false;
		while (!q.empty())
		{
			int cur = q.front().second;
			int curN = q.front().first;
			q.pop();
			if(cur < 0) continue;
			if (cur >= node1 && cur <= node2 && !decI[cur])
			{
				ans.push_back(curN);
				isIn = true;
				break;
			}
			for (int i = 0; i < 4; i++)
			{
				int nx = cal(cur, i);
				if (vst[nx])
					continue;
				vst[nx] = true;
				q.push({curN + 1, nx});
			}
		}
		if(!isIn)
		{	
			ans.push_back(-1);
		}
	}
	for(int i=0;i<ans.size();i++)
	{
		cout << ans[i] << "\n";
	}
}
