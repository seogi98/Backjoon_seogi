#include<stdio.h>
#include <algorithm>
#include <queue>
#include<iostream>
#include<stdlib.h>

using namespace std;


struct cmp{
    bool operator()(int t, int u){
        if(abs(t)==abs(u))
        {
            return t>u;
        }
        else{
            return abs(t)>abs(u);
        }
    }
};

int main()
{
    int N;
    int t;
    priority_queue<int,vector<int>,cmp> q;
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
