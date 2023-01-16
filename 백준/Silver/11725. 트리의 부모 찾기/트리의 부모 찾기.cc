#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <queue>
#include <string.h>
#include<vector>
#define MAX 100001
using namespace std;

// parent 배열을 만들어 입력된 정점중 부모노드를 찾아 바로 기록한다
// 부모노드는 parent배열에 기록된적이 있는 노드가 부모노드가 된다.

bool vst[MAX];
int parent[MAX];
vector<int> tree[MAX]; // tree[node1]->[node2]로 이동한다.
int N;
void findparnet(int nodeNum)
{
    //방문한 노드 표시
    vst[nodeNum] = true;
    //nodenum에서 연결되어 있는 모든 노드를 탐색한다.
    for(int i=0;i<tree[nodeNum].size();i++)
    {
        int next = tree[nodeNum][i];
        if(!vst[next])
        {
            parent[next] = nodeNum; // next의 parent는 이전노드인 nodeNum
            findparnet(next); // 그다음 자식노드에 연결된 노드를 탐색한다.
            //DFS 방식
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); 
    cout.tie(NULL);
    cin >> N;
    for(int i=0;i<N-1;i++)
    {
        int node1,node2;
        cin >> node1 >> node2;
        //입력의 순서는 랜덤이므로 데이터를 양방향으로 넣어줘야한다.
        tree[node1].push_back(node2); // node1 에서 node2
        tree[node2].push_back(node1); // node2 에서 node1
    }
    findparnet(1);
    for(int i=2;i<=N;i++)
    {
        cout << parent[i] << "\n";
    }
    return 0;
}
