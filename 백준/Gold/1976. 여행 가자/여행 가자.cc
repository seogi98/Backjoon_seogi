#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <queue>
#include <string.h>
#include <vector>
#define MAX 10001
using namespace std;


int N,M;
int P[1001];
int find(int curNode)
{
    if(curNode==P[curNode])
    {
        return curNode;
    }
    return find(P[curNode]);
    
}
int main()
{
    ios::sync_with_stdio(false);
    cin >> N >> M;
    for(int i=1;i<=N;i++)
    {
        P[i] = i;
    }
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=N;j++)
        {
            int isConnect;
            cin >> isConnect;
            if(isConnect == 1)
            {
                int node1 = find(i);
                int node2 = find(j);
                if(node1 != node2)
                {
                    P[node1] = j;
                }
            }
        }
    }
    int node1;
    cin >> node1;
    int node1R;
    node1R = find(node1); 
    for(int i=1;i<M;i++)
    {
        int node2;
        cin >> node2;
        int node2R = find(node2);
        if(node2R !=node1R)
        {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
}
