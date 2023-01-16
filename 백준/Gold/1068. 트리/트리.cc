#include <string>
#include <math.h>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <string.h>
#define MAX 4000
#define INF 10000001
using namespace std;
vector<int> tree[MAX];
int root;
int N;
int leafN=0;
int delNode;
int findLeaf(int curNode)
{
    int result=0;
    if(tree[curNode].empty())
    {
       //cout << curNode << " ";
       return 1;
    }
    int Tlen = tree[curNode].size();
    for(int i=0;i<Tlen;i++)
    {
        result+=findLeaf(tree[curNode][i]);
    }
    return result;
}
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    int P[MAX];
    for(int i=0;i<N;i++)
    {
        int T;
        cin >> T;
        if(T == -1)
        {
            root = i;
            continue;
        }
        tree[T].push_back(i);
        P[i] = T;
    }
    cin >> delNode;
    if(tree[P[delNode]].size()==1&&delNode != root)
    {
        cout << findLeaf(root) - findLeaf(delNode)+1;
        return 0;
    }
    cout << findLeaf(root) - findLeaf(delNode);

}
