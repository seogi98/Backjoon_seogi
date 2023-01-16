#include <iostream>
#include <vector>
#include <queue>
using namespace std;
//1 -> node 1 -> node 2 -> N으로 가는것과
//1 -> node 2 -> node 1 -> N으로 가는것중 최소값을 비교한다.

const long long MAX = 800 + 1;
const long long INF = 987654321;
long long V, E, K;
long long A,B;
//long long trace[MAX];
vector<pair<long long, long long>> graph[MAX];
vector<long long> dijkstra(long long start, long long vertex)
{
    vector<long long> distance(vertex, INF); //start를 기준으로 거리distance[vertex] = inf
    distance[start] = 0;               //자기 자신한테 가는 비용 0
    priority_queue<pair<long long, long long>> pq; //Cost, Vertex
    pq.push(make_pair(0, start));      //초기 비용과 시작점
    while (!pq.empty())
    {
        long long cost = pq.top().first; 
        long long curVertex = pq.top().second;
        pq.pop();
        //최소거리를 원하므로
        if (distance[curVertex] < cost)
            continue;
        //neighbor 다 확인
        for (long long i = 0; i < graph[curVertex].size(); i++)
        {
            long long neighbor = graph[curVertex][i].first;
            long long neighborDistance = cost + graph[curVertex][i].second;
            //최소 경로 발견시 업데이트
            if (distance[neighbor] > neighborDistance)
            {
                distance[neighbor] = neighborDistance;
                pq.push(make_pair(neighborDistance, neighbor));
            }
        }
    }
    return distance;
}
int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> V >> E;//V는 정점 E는 간선
    vector<long long> result;//1->N으로 갈때 그려지는 다익스트라 결과값 저장
    vector<long long> node1; // 중간 노드 1
    vector<long long> node2; // 중간 노드 2
    long long ans=0;
    V++; //정점번호 1부터 시작
    for (long long i = 0; i < E; i++)
    {
        long long source, destination, cost;
        cin >> source >> destination >> cost;
        graph[source].push_back(make_pair(destination, cost));
        graph[destination].push_back(make_pair(source, cost));
    }
    cin >> A >> B;
    result = dijkstra(1,V);
    node1 = dijkstra(A,V);
    node2 = dijkstra(B,V);

    ans = min((result[A]+node1[B]+node2[V-1]),(result[B]+node2[A]+node1[V-1]));
    if(ans >=INF ||ans ==0)
    {
        cout << -1<<endl;
    }
    else
    {
        cout <<ans<<endl;
    }
    
    return 0;
}