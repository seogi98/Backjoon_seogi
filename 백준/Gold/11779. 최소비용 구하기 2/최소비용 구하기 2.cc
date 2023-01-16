#include <bits/stdc++.h>
using namespace std;
#define MAX 100001
#define INF 9999999999999
long long N, M;
long long dst[MAX];
priority_queue<pair<pair<long long, long long>, vector<long long>>> pq;
vector<pair<long long, long long>> V[MAX];
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    vector<long long> trace[MAX];
    cin >> N >> M;
    for (long long i = 1; i <= N; i++)
    {
        dst[i] = INF;
    }
    for (long long i = 0; i < M; i++)
    {
        long long node1, node2, weight;
        cin >> node1 >> node2 >> weight;
        V[node1].push_back({node2, weight});
    }
    long long start, end;
    cin >> start >> end;
    dst[start] = 0;
    vector<long long> tmp;
    pq.push({{0, start}, tmp});
    while (!pq.empty())
    {
        long long curNode = pq.top().first.second;
        long long curWeight = -pq.top().first.first;
        vector<long long> curV = pq.top().second;
        curV.push_back({curNode});
        pq.pop();
        if(curWeight > dst[curNode])
        {
            continue;
        }
        for (long long i = 0; i < V[curNode].size(); i++)
        {
            long long nextNode = V[curNode][i].first;
            long long nextWeight = V[curNode][i].second + curWeight;
            //거리가 작을떄
            if (nextWeight < dst[nextNode])
            {
                dst[nextNode] = nextWeight;
                trace[nextNode] = curV;
                pq.push({{-nextWeight, nextNode}, curV});
            }
        }
    }
    cout << dst[end] << "\n";
    cout << trace[end].size()+1 << "\n";
    for (long long i = 0; i < trace[end].size(); i++)
    {
        cout << trace[end][i] << " ";
    }
    cout << end;
}
