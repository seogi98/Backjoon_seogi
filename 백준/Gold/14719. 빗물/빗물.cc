#include<stdio.h>
#include<algorithm>
#include<queue>
using namespace std;


priority_queue<int, vector<int>,less<int>> q;

int main(void)
{
	int map[500];
	int tmp[500];
	int check;
	int min = 0;
	int max = 0;
	int total = 0;
	int sum=0;
	int H, W;
	int result;
	scanf("%d %d", &H, &W);

	for (int i = 0; i < W; i++)
	{
		scanf("%d", &map[i]);
		sum += map[i];
	}
	for (int i = H; i > 0; i--)
	{

		max = 0;
		min = 0;
		for (int j = 0; j < W; j++)
		{
			if (map[j] >= i) {
				q.push(j);
			}
		}
		if (!q.empty()) {
			max = q.top();
			while (!q.empty())
			{
				min = q.top();
				q.pop();
			}
			total = total +(W - (max - min + 1));
		}
		else
		{
			total += W;
		}
	}

	printf("%d", W*H - total - sum);

}