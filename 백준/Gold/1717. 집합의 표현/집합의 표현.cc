#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <queue>
#include <string.h>
#include <vector>
#define MAX 10001
using namespace std;


int p[1000001];
//p[node1] = node2;
int N,M;
//부모노드를 찾는과정
int find(int x)
{
    if(x==p[x])
    {
        return x;
    }
    else{
        return p[x] = find(p[x]);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    for(int i=0;i<=N;i++)
    {
        p[i] = i;
    }
    while(M--)
    {
        int op,node1,node2;
        int node1R,node2R;
        cin >> op >> node1 >> node2;
        switch (op)
        {
        case 0:
            node1R = find(node1);
            node2R = find(node2);
            if(node1R > node2R)
            {
                p[node1R] = node2R;
            }
            else if(node1R<node2R)
            {
                p[node2R] = node1R;
            }
            break;
        case 1:
            if(find(node1) == find(node2))
            {
                cout << "yes\n";
            }
            else
            {
                cout << "no\n";
            }
            break;
        default:
            break;
        }
    }
}
