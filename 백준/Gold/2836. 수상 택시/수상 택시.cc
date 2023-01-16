#include <bits/stdc++.h>
using namespace std;
#define MAX 1010
#define INF 1987654321
priority_queue<pair<long long, long long>> pq;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    long long N, M;
    cin >> N >> M;
    vector<pair<long long, long long>> P;
    long long result = 0;
    for (long long i = 0; i < N; i++)
    {
        long long node1, node2;
        cin >> node1 >> node2;
        if (node1 <= node2)
        {
            continue;
        }
        pq.push({-node2, -node1});
    }
    pair<long long, long long> line = {-1, -1};
    while (!pq.empty())
    {
        long long L = -pq.top().first;
        long long R = -pq.top().second;
        pq.pop();
        if (line.second < L)
        {
            result += line.second - line.first;
            line.first = L;
            line.second = R;
            continue;
        }
        if (line.second < R)
        {
            line.second = R;
        }
    }
    result += line.second - line.first;
    cout <<  M+result*2;
    return 0;
}
