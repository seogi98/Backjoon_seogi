#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX 200000
#define INF 2147483611
int N,S,D;
int tree[MAX];
vector<int> E[MAX];
pair<int,int> T[MAX];
// 이동거리 , 뿌리로 부터의 거리의 최대값
pair<int,int> findT(int cur,int pre)
{
    if(E[cur].size() == 1 && cur != S) 
    {
        if(D == 0) return {2,0};
        return {0,0};
    }
    pair<int,int> re = {0,0};
    for(int i=0;i<E[cur].size();i++)
    {
        int nx = E[cur][i];
        if(nx == pre) continue;
        pair<int,int> result = findT(nx,cur);
        re.second = max(re.second,result.second);
        re.first += result.first;
    }
    // 뿌리부터 깊이가 D보다 작으면 접근할 필요가없으므로
    re.second++;
    if(re.second<D)
    {
        return T[cur] = re;
    }
    if(cur !=S)
    re.first +=2;
    return T[cur] = re;
}
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
    cin >> N >> S >> D;
    for(int i=0;i<N-1;i++)
    {
        int node1 , node2;
        cin >> node1 >> node2;
        E[node1].push_back(node2);
        E[node2].push_back(node1);
    }
    findT(S,0);
    cout << T[S].first;
    cout << "\n";
}