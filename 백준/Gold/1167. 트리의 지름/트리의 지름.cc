#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <queue>
#include <string.h>
#include <vector>
#define MAX 100001
using namespace std;

bool vst[MAX];
int parent[MAX];
vector<pair<int, int>> tree[MAX]; //( first = node2 , second = len )
int N;
int mx = 0;
int farthestNode = 0;

void findLen(int curNode, int result)
{
    if(vst[curNode])
        return;
        
    vst[curNode] = true;
    if (mx < result)
    {
        mx = result;
        farthestNode = curNode;
    }
    for (int i = 0; i < tree[curNode].size(); i++)
    {
        //bool block = true;
        int next = tree[curNode][i].first;
        findLen(next, result + tree[curNode][i].second);
    }
    return;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    vector<int> firstNode;
    for (int i = 0; i < N; i++)
    {
        int node1;
        cin >> node1;
        firstNode.push_back(node1);
        while (1)
        {
            int node2, len;
            cin >> node2;
            if (node2 == -1)
            {
                break;
            }
            cin >> len;
            tree[node1].push_back({node2, len});
        }
    }
    memset(vst, false, sizeof(vst));
    findLen(firstNode[0], 0);
    memset(vst, false, sizeof(vst));
    mx = 0;
    findLen(farthestNode, 0);
    cout << mx << "\n" ;
    return 0;
}
