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
    if (vst[curNode])
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
    cin >> N;
    vector<int> firstNode;
    for (int i = 0; i < N-1; i++)
    {
        int node1,node2, len;
        cin >> node1 >> node2 >> len;
        tree[node1].push_back({node2, len});
        tree[node2].push_back({node1, len});
    }
    memset(vst, false, sizeof(vst));
    findLen(1, 0);
    mx = 0;
    //cout << farthestNode << "\n";
    memset(vst, false, sizeof(vst));
    findLen(farthestNode, 0);
    cout << mx << "\n";
    return 0;
}
