#include<bits/stdc++.h>
using namespace std;
#define MAX 100001
vector<int> P(2*MAX,0);
map<string,int> convert;

int unionFind(int cur)
{
    if(cur == P[cur])
    {
        return cur;
    }
    return P[cur] = unionFind(P[cur]);
}
int main(void)
{
     ios::sync_with_stdio(false);
     cin.tie(NULL);
    int T;
    cin >> T;
    while(T--)
    {

        int idx=1;
        int N;
        P.clear();
        convert.clear();
        vector<pair<string,string>> E;
        int nodeCount[MAX*2];
        cin >> N;
        for(int i=1;i<=MAX*2;i++)
        {
            P[i] = i;
            nodeCount[i] = 1;
        }
        for(int i=0;i<N;i++)
        {
            string node1, node2;
            cin >> node1 >> node2;
            E.push_back({node1,node2});
            if(convert[node1]==0)
            {
                convert[node1] = idx;
                idx++;
            }
            if(convert[node2]==0)
            {
                convert[node2] = idx;
                idx++;
            }
        }
        for(int i=0;i<E.size();i++)
        {
            int node1 = convert[E[i].first];
            int node2 = convert[E[i].second];
            int node1P = unionFind(node1);
            int node2P = unionFind(node2);
            // 만약에 같지않은 노드이면
            if(node1P != node2P)
            {
                P[node2P] = node1P;
                nodeCount[node1P] += nodeCount[node2P];
                nodeCount[node2P] = 1;
            }
            cout << nodeCount[node1P] << "\n";
        }
    }
}