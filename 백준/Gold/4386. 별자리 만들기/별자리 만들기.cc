#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <queue>
#include <string.h>
#include <vector>
#include <math.h>
#include <map>

#define MAX 100000
using namespace std;
int P[MAX];
typedef struct Point{
    int num;
    double X;
    double Y;
}pnt;

typedef struct Edge{
    pnt node1;
    pnt node2;
    double weight;
}edge;
vector<edge> ed;
vector<pnt> pt;
double result =0;
bool cmp(edge e1,edge e2){
    return e1.weight<e2.weight?true:false;
}
int find(int curNode)
{
    if(P[curNode]==curNode)
    {
        return curNode;
    }
    else 
        return find(P[curNode]);
}
void unionFind(edge e)
{
    int node1R = find(e.node1.num);
    int node2R = find(e.node2.num);
    if(node1R != node2R)
    {
        P[node1R] = node2R;
        result+=e.weight;
    }
}
int main()
{
    int N;
    cin >> N;
    for(int i=0;i<MAX;i++)
    {
        P[i] = i;
    }
    for(int i=1;i<=N;i++)
    {
        pnt ptT;
        cin >> ptT.X >> ptT.Y;
        ptT.num = i;
        pt.push_back(ptT);
    }
    for(int i=0;i<N-1;i++)
    {
        for(int j=i+1;j<N;j++)
        {
            edge tmpE;
            tmpE.node1 = pt[i];
            tmpE.node2 = pt[j];
            tmpE.weight = sqrt(pow(fabs(tmpE.node1.X-tmpE.node2.X),2)+pow(fabs(tmpE.node1.Y-tmpE.node2.Y),2));
            ed.push_back(tmpE);
        }
    }
    sort(ed.begin(),ed.end(),cmp);
    for(int i=0;i<ed.size();i++)
    {
        //cout << ed[i].weight << "\n";
        unionFind(ed[i]);
    }
    cout << result;
}
