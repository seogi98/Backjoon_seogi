#include<stdio.h>
#include <algorithm>
#include <stdio.h>
#include <queue>
using namespace std;
int main()
{
    int N;
    int t;
    priority_queue<int> q;
    scanf("%d",&N);
    for(int i=0;i<N;i++)
    {
        scanf("%d",&t);
        if(t==0)
        {
            if(!q.empty())
            {
                printf("%d\n",q.top());
                q.pop();
            }
            else
            {
                printf("0\n");
            }
        }
        else
        {
            q.push(t);
        }

    }
}
