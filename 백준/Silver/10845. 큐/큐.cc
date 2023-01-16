#include<iostream>
#include<string>
#include<deque>
#include<queue>
using namespace std;
queue<int>q;
int main(){
int N, t;
string word;
scanf("%d", &N);

while (N--)
{
	cin >> word;
	if (word == "push")
	{
		cin >> t;
		q.push(t);
	}
	else if (word == "front")
	{
		if (!q.empty())
			printf("%d\n", q.front());
		else
			printf("-1\n");
	}
	else  if (word == "pop")
	{
		if (!q.empty())
		{
			printf("%d\n", q.front());
			q.pop();
		}
		else
			printf("-1\n");

	}
	else if (word == "size")
	{
		printf("%d\n", q.size());
	}
	else if (word == "empty")
	{
		printf("%d\n", q.empty());
	}
	else if (word == "back")
	{
		if (!q.empty())
		{
			printf("%d\n", q.back());
		}
		else
			printf("-1\n");
	}


}
}