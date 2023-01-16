#include <bits/stdc++.h>
using namespace std;
#define MAX 300010
int pt[MAX];
bool ext[MAX];
int find(int curNode)
{
    if(curNode == pt[curNode])
    {
        return curNode;
    }
    return pt[curNode] = find(pt[curNode]);
}
void merge(int node1,int node2)
{
    node1 = find(node1);
    node2 = find(node2);
    pt[node1] = node2;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N,L; // 술병 N개 서랍 L개
    cin >> N >> L;
    memset(ext,false,sizeof(ext));
    for(int i=0;i<=L;i++)
    {
        pt[i]= i;
    }
    for(int i=1;i<=N;i++)
    {
        int node1, node2;
        cin >> node1 >> node2;
        int node1R = find(pt[node1]); // node1 root
        int node2R = find(pt[node2]); // node2 root
        // case 1 : A 서랍에 자리가 있는경우
        if(!ext[node1]) 
        {
            ext[node1] = true;
            merge(node1,node2);
            cout << "LADICA"<<"\n"; 
            continue;
        }
        // case 2 : B 서랍에 자리가 있는경우
        if(!ext[node2]) 
        {
            ext[node2] = true;
            merge(node2,node1);
            cout << "LADICA"<<"\n"; 
            continue;
        }
        // case 3 : A 서랍에 자리가 없는경우
        if(!ext[node1R])
        {
            ext[node1R] = true;
            merge(node1R,node2R);
            cout << "LADICA"<<"\n"; 
            continue;
        }
        // case 4 : B 서랍에 자리가 없는경우
        if(!ext[node2R])
        {
            ext[node2R]=true;
            merge(node2R,node1R);
            cout << "LADICA"<<"\n"; 
            continue;
        }
        //마시는 경우
        cout << "SMECE" <<"\n"; 
    }
 }