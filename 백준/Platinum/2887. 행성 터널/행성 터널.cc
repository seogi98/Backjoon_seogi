#include<bits/stdc++.h>
#define MAX 100001
using namespace std;
int P[MAX];
typedef struct Point
{
	int num;
	int X;
	int Y;
	int Z;
} pnt;

typedef struct Edge
{
	pnt node1;
	pnt node2;
	int weight;
} edge;
vector<edge> ed;
vector<pnt> pt;
int result = 0;
int cnt=0;
int getWeight(edge e)
{
	return min(min(abs(e.node1.X - e.node2.X), abs(e.node1.Y - e.node2.Y)), abs(e.node1.Z - e.node2.Z));
}
bool cmp(edge e1, edge e2)
{
	return e1.weight < e2.weight;
}
bool cmpx(pnt p1, pnt p2)
{
	return p1.X < p2.X;
}
bool cmpy(pnt p1, pnt p2)
{
	return p1.Y < p2.Y;
}
bool cmpz(pnt p1, pnt p2)
{
	return p1.Z < p2.Z;
}
int find(int curNode)
{
	if (P[curNode] == curNode)
	{
		return curNode;
	}
	else
		return P[curNode] = find(P[curNode]);
}
void unite(edge e)
{
	int node1R = find(e.node1.num);
	int node2R = find(e.node2.num);
	if (node1R != node2R)
	{
		P[node1R] = node2R;
		result += e.weight;
		cnt++;
		return;
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, M;
	edge tmpE;
	pnt ptT;
	cin >> N;
	for (int i = 0; i < MAX; i++)
	{
		P[i] = i;
	}
	for (int i = 1; i <= N; i++)
	{
		cin >> ptT.X >> ptT.Y >> ptT.Z;
		ptT.num = i;
		pt.push_back(ptT);
	}
	sort(pt.begin(),pt.end(),cmpx);
	for(int i=0;i<pt.size()-1;i++)
	{
		edge E;
		E.node1 = pt[i];
		E.node2 = pt[i+1];
		E.weight = getWeight(E);
		ed.push_back(E);
	}
	sort(pt.begin(),pt.end(),cmpy);
	for(int i=0;i<pt.size()-1;i++)
	{
		edge E;
		E.node1 = pt[i];
		E.node2 = pt[i+1];
		E.weight = getWeight(E);
		ed.push_back(E);
	}
	sort(pt.begin(),pt.end(),cmpz);
	for(int i=0;i<pt.size()-1;i++)
	{
		edge E;
		E.node1 = pt[i];
		E.node2 = pt[i+1];
		E.weight = getWeight(E);
		ed.push_back(E);
	}
	sort(ed.begin(),ed.end(),cmp);


	for (int i = 0; i < ed.size(); i++)
	{
		unite(ed[i]);
		if(cnt == N) break;
	}
	cout << result;
}