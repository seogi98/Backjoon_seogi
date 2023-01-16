#include <bits/stdc++.h>
using namespace std;
#define MAX 100010
#define INF 999999999
int pt[MAX];

int find(int curNode)
{
    if(curNode == pt[curNode])
    {
        return curNode;
    }
    return pt[curNode] = find(pt[curNode]);
}

void unite(int node1,int node2)
{
    node1 = find(node1);
    node2 = find(node2);
    pt[node1] = node2;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int G,P;
    int result=0;
    cin >> G >> P;
    for(int i=0;i<=G;i++)
    {
        pt[i] = i;
    }
    //N번게이트에 도킹되었을 경우 다음에 들어오는 노드는 unionfind(N)로 가야한다. 
    for(int i=1;i<=P;i++)
    {
        int node1;
        cin >> node1;
        int node1R = find(node1);
        if(node1R == 0) break;
        unite(node1R,node1R-1);
        result++;
    }   
    cout << result;
    return 0;
}