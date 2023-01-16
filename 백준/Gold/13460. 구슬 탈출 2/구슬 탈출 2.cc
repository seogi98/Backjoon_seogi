#include <bits/stdc++.h>
using namespace std;
#define MAX 11
int N, M;
map<pair<vector<vector<char>>, int> ,bool> vst[MAX];
void seeM(vector<vector<char>> mp)
{
	cout << "\n";
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cout << mp[i][j] << " ";
		}
		cout << "\n";
	}
}
// 왼쪽으로 기울일 경우 => 왼쪽에 있는거 부터 이동시켜야한다.
// input : 0 => 왼쪽 , 1 => 오른쪽 , 2 => 위쪽 , 3 => 아래쪽
// output : 이동한 후 vector , -1 => B 나옴 , 0 => 안나옴 , 1 => R 나옴
pair<vector<vector<char>>, int> moveBall(vector<vector<char>> mp, int dir)
{
	pair<vector<vector<char>>, int> result = {mp, 0};
	// 왼쪽으로 이동할 경우
	if (dir == 0)
	{
		// 가로
		for (int j = 0; j < M; j++)
		{
			// 세로
			for (int i = 0; i < N; i++)
			{
				// 구슬이 아닌경우
				if (mp[i][j] == '#' || mp[i][j] == '.' || mp[i][j] == 'O')
					continue;
				// 구슬일 경우 벽이 나올때 까지 왼쪽으로 이동한다.
				int k = 0;			 //왼쪽으로 이동할 칸수
				char tmp = mp[i][j]; // 이동할 구슬
				mp[i][j] = '.';
				while (mp[i][j - k] == '.' || mp[i][j - k] == 'O')
				{
					if (mp[i][j - k] == 'O')
					{
						// 파란 구슬 return
						if (tmp == 'B' || result.second == -1)
						{
							result.second = -1;
							break;
						}
						// 빨강 구슬 return
						result.second = 1;
						break;
					}
					k++;
				}
				if (result.second == 0)
				{
					mp[i][j - k + 1] = tmp;
				}
			}
		}
	}
	// 오른쪽으로 이동할 경우
	if (dir == 1)
	{
		// 가로
		for (int j = M - 1; j >= 0; j--)
		{
			// 세로
			for (int i = 0; i < N; i++)
			{
				//구슬이 아닌경우
				if (mp[i][j] == '#' || mp[i][j] == '.' || mp[i][j] == 'O')
					continue;
				//구슬일 경우 벽이 나올때 까지 왼쪽으로 이동한다.
				int k = 0;			 //왼쪽으로 이동할 칸수
				char tmp = mp[i][j]; // 이동할 구슬
				mp[i][j] = '.';
				while (mp[i][j + k] == '.' || mp[i][j + k] == 'O')
				{
					if (mp[i][j + k] == 'O')
					{
						// 파란 구슬 return
						if (tmp == 'B' || result.second == -1)
						{
							result.second = -1;
							break;
						}
						// 빨강 구슬 return
						result.second = 1;
						break;
					}
					k++;
				}
				if (result.second == 0)
				{
					mp[i][j + k - 1] = tmp;
				}
			}
		}
	}
	// 위로 이동할 경우
	if (dir == 2)
	{
		// 세로
		for (int i = 0; i < N; i++)
		{
			// 가로
			for (int j = 0; j < M; j++)
			{
				//구슬이 아닌경우
				if (mp[i][j] == '#' || mp[i][j] == '.' || mp[i][j] == 'O')
					continue;
				//구슬일 경우 벽이 나올때 까지 왼쪽으로 이동한다.
				int k = 0;			 //왼쪽으로 이동할 칸수
				char tmp = mp[i][j]; // 이동할 구슬
				mp[i][j] = '.';
				while (mp[i - k][j] == '.' || mp[i - k][j] == 'O')
				{
					if (mp[i - k][j] == 'O')
					{
						// 파란 구슬 return
						if (tmp == 'B' || result.second == -1)
						{
							result.second = -1;
							break;
						}
						// 빨강 구슬 return
						result.second = 1;
						break;
					}
					k++;
				}
				if (result.second == 0)
				{
					mp[i - k + 1][j] = tmp;
				}
			}
		}
	}
	// 아래로 이동할 경우
	if (dir == 3)
	{
		// 가로
		for (int i = N - 1; i >= 0; i--)
		{
			// 세로
			for (int j = 0; j < M; j++)
			{
				//구슬이 아닌경우
				if (mp[i][j] == '#' || mp[i][j] == '.' || mp[i][j] == 'O')
					continue;
				//구슬일 경우 벽이 나올때 까지 왼쪽으로 이동한다.
				int k = 0;			 //왼쪽으로 이동할 칸수
				char tmp = mp[i][j]; // 이동할 구슬
				mp[i][j] = '.';
				while (mp[i + k][j] == '.' || mp[i + k][j] == 'O')
				{
					if (mp[i + k][j] == 'O')
					{
						// 파란 구슬 return
						if (tmp == 'B' || result.second == -1)
						{
							result.second = -1;
							break;
						}
						// 빨강 구슬 return
						result.second = 1;
						break;
					}
					k++;
				}
				if (result.second == 0)
				{
					mp[i + k - 1][j] = tmp;
				}
			}
		}
	}
	result.first = mp;
	return result;
}
//result, 횟수
int dfs(pair<vector<vector<char>>, int> result, int N)
{
	pair<vector<vector<char>>, int> tmp = result;
	int ans = MAX;
	if(N > 10)
	{
		return ans;
	}
	for (int i = 0; i < 4; i++)
	{
		tmp = moveBall(result.first,i);
        if(vst[N][tmp]) continue;
		if(tmp.second == -1) continue;
        vst[N][tmp] = true;
		if(tmp.second == 1)
		{
			return N; 
		}
		ans = min(dfs(tmp,N+1),ans);
	}
	return ans;
}
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int ans=0;
	cin >> N >> M;
	vector<vector<char>> mp(MAX, vector<char>(MAX, '0'));
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> mp[i][j];
		}
	}
	pair<vector<vector<char>>, int> result = {mp, 0};
	ans = dfs(result,1);
	if(ans == MAX)
	{
		ans = -1;
	}
	cout << ans;
} 