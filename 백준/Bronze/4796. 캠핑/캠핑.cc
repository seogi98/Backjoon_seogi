#include<cstdio>
#include<iostream>
using namespace std;
int p;
int l;
int v;
int temp;
int result;
int main(void)
{
	int i = 1;
	while (1)
	{
		temp = 0; result = 0;
		scanf("%d", &p);
		scanf("%d", &l);
		scanf("%d", &v);
		if ((p == 0) && (l == 0) && (v == 0))
		{
			break;
		}
		temp = v / l;
		result = p * temp;
		if (v - l * temp > p)
		{
			result += p;
		}
		else
		{
			result += v - l * temp;
		}
		printf("Case %d: %d\n", i, result);
		i++;


	}

}
