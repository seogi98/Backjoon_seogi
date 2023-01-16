#include <bits/stdc++.h>
#define MAX 100
using namespace std;
#define INF 98765432

// 첫번쨰로 union 으로 묶고
// 진실인 사람이랑 묶여있는 사람들 true표시
// 파티를 돌면서 진실을 알고있는 사람 없는경우 ans++

// 진실을 알고 있는 사람 parent
bool parentT[MAX];
// 진실을 알고 있는 사람
vector<int> T;
int P[MAX];
vector<int> party[MAX];
int ufind(int cur)
{
    if(cur == P[cur])
    {
        return P[cur];
    }
    return P[cur] = ufind(P[cur]);
}
void merge(int node1,int node2)
{
    int node1P = ufind(node1);
    int node2P = ufind(node2);
    if(node1P == node2P) return;
    P[node1P] = node2P;
}
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N,M;
    cin >> N >> M;
    int ans=0;
    memset(parentT,false,sizeof(parentT));
    // 진실을 아는 사람의 수
    int trueN;
    cin >> trueN;
    for(int i=0;i<=N;i++)
    {
        P[i] = i;
    }
    while(trueN--)
    {
        // 진실을 아는 사람
        int trueP;
        cin >> trueP;
        T.push_back(trueP);
    }
    // 파티를 돌면서
    for(int i=0;i<M;i++)
    {
        // 파티 사람의 수
        int Pnum;
        cin >> Pnum;
        int pre;
        for(int j=0;j<Pnum;j++)
        {
            // 파티 사람
            int PP;
            cin >> PP;
            if(j==0)
            {
                pre = PP;
                party[i].push_back(PP);
                continue;
            }
            merge(pre,PP);
            party[i].push_back(PP);
        }
    }
    // 진실 노드 parent 표시
    for(int i=0;i<T.size();i++)
    {
        int cur = T[i];
        parentT[ufind(cur)] = true;
    }
    for(int i=0;i<M;i++)
    {
        bool partyIsTrue = false;
        //노드를 돌면서
        for(int j=0;j<party[i].size();j++)
        {
            //만약에 진실을 알고있는 사람이 있다면 break;
            if(parentT[ufind(party[i][j])])
            {
                partyIsTrue = true;
                break;
            }
        }
        if(!partyIsTrue) ans++;
    }
    cout << ans;
}