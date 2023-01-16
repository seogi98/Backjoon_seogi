#include <bits/stdc++.h>
using namespace std;
#define MAX 101
#define INF 999999999999999
int T[MAX];
vector<string> V(101,"");
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string ans= "";
	int N,H,W; //문자열 , 세로 , 가로
	cin >> N >> H >> W;
	for(int i=0;i<H;i++)
	{
		cin >> V[i];
	}
	int spread = V[0].size()/N;
	//가로
	for(int i=0;i<N;i++)
	{
		//세로
		bool isKnow = false;
		char input = '?';
		for(int j=0;j<H;j++)
		{
			int start = i*spread;
			for(int k=0;k<spread;k++)
			{
				char curC = V[j][start+k];
				if(curC != '?')
				{
					isKnow = true;
					input = curC;
					break;
				}
			}
		}
		ans.push_back(input);

	}
	cout << ans;

}
