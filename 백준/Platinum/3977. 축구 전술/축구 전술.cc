#include <bits/stdc++.h>
using namespace std;
#define MAX 100010

bool vst[MAX];
stack<int> st;     // 정방향 dfs시 push
vector<int> cycle; // cycle 저장

//정방향 dfs
void dfs(const vector<int> V[MAX], int curNode)
{
    if (vst[curNode])
    {
        return;
    }
    vst[curNode] = true;
    for (int i = 0; i < V[curNode].size(); i++)
    {
        int nextNode = V[curNode][i];
        if (!vst[nextNode])
        {
            dfs(V, nextNode);
        }
    }
    st.push(curNode);
}
//역방향 dfs
void dfsR(const vector<int> RV[MAX], int curNode)
{
    if (vst[curNode])
    {
        return;
    }
    vst[curNode] = true;
    cycle.push_back(curNode);
    for (int i = 0; i < RV[curNode].size(); i++)
    {
        int nextNode = RV[curNode][i];
        if (!vst[nextNode])
        {
            dfsR(RV, nextNode);
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--)
    {
        int N, M;
        int result = 0;
        cin >> N >> M;     // 도미노, 관계
        int indegree[MAX]; // 진입차수
        memset(vst, false, sizeof(vst));
        memset(indegree, 0, sizeof(indegree));
        stack<int> tmp;
        st = tmp;
        vector<int> V[MAX];
        vector<int> RV[MAX];
        for (int i = 1; i <= M; i++)
        {
            int node1, node2;
            cin >> node1 >> node2;
            V[node1].push_back(node2);
            indegree[node2]++;
            RV[node2].push_back(node1);
        }
        for (int i = 0; i < N; i++)
        {
            dfs(V, i);
        }
        memset(vst, false, sizeof(vst));
        bool ex[MAX];
        memset(ex, false, sizeof(ex));
        vector<vector<int>> ans;
        bool confused = false;
        while (!st.empty()) // cycle 끼리 묶기
        {
            int Rstart = st.top();
            st.pop();
            if (ex[Rstart])
                continue;
            cycle.clear();
            dfsR(RV, Rstart); // 역방향 dfs로 cycle 찾음
            //만약에 cycle중에 진입차수가 1인경우가 있을경우 continue
            //없을경우 위상정렬의 시작부분이므로 result++
            for (int i = 0; i < cycle.size(); i++)
            {
                ex[cycle[i]] = true;
            }
            for (int i = 0; i < cycle.size(); i++)
            {
                int curNum = cycle[i];
                for (int j = 0; j < V[curNum].size(); j++)
                {
                    int nextNum = V[curNum][j];
                    if (ex[nextNum])
                    {
                        indegree[V[curNum][j]]--;
                    }
                }
            }
            bool isI = false;
            for (int i = 0; i < cycle.size(); i++)
            {
                int curNum = cycle[i];  
                if (indegree[cycle[i]] != 0)
                    isI  = true;
            }
            if(!isI)
            {
                ans.push_back(cycle);
            }
        }
        if(ans.size()>1 || ans.empty()){
            cout << "Confused\n\n";
            continue;
        } 
        sort(ans[0].begin(),ans[0].end());
        for(int i=0;i<ans[0].size();i++)
        {
            cout << ans[0][i] << '\n';
        }
        cout << "\n";
    }
}