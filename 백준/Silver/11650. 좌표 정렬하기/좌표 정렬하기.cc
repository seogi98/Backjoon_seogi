#include<stdio.h>

#include<algorithm>

using namespace std;

typedef struct point
{
	int x;
	int y;
}P;
bool compare(P p1, P p2)
{
	if (p1.x == p2.x)
	{
		return p1.y < p2.y;
	}
	else
	{
		return p1.x < p2.x;
	}
}
int main(void)
{
	P p[100000];
	int n=0;
	int x, y;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d %d", &x, &y);	
		p[i].x = x;
		p[i].y = y;
	}
	sort(p, p+n, compare);
	for (int i = 0; i < n; i++)
	{
		printf("%d %d\n", p[i].x, p[i].y);
	}
}