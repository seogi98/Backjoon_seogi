#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <queue>
#include <string.h>
#include <vector>
#define MAX 10001
using namespace std;

bool vst[MAX];
char parent[MAX];
pair<char, char> tree[MAX]; // <left,right>
int N;
void preOrder(char curNode) //현제 노드 , 출력
{
    if(curNode=='.')
    {
        return;
    }
    else
    {
        cout << curNode;
        preOrder(tree[curNode].first);
        preOrder(tree[curNode].second);
    }
}
void inOrder(char curNode)
{
    if(curNode=='.')
    {
        return;
    }
    else
    {
        inOrder(tree[curNode].first);
        cout << curNode;
        inOrder(tree[curNode].second);
    }
}
void postOrder(char curNode)
{
    if(curNode=='.')
    {
        return;
    }
    else
    {
        postOrder(tree[curNode].first);
        postOrder(tree[curNode].second);
        cout << curNode;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        char curNode, left, right;
        cin >> curNode >> left >> right;
        tree[curNode].first = left;
        tree[curNode].second = right;
    }
    preOrder('A');
    cout << "\n";
    inOrder('A');
    cout << "\n";
    postOrder('A');
}
