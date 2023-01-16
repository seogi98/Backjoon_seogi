#include<iostream>
#include<vector>
#include<queue>
#define INF 987654321
#define MAX_NODE 501
using namespace std;

typedef struct EDGE{
    long long nextNode;
    long long weight;
}EDGE;

//0번 인덱스는 버린다.

vector<EDGE> E[MAX_NODE];
long long V[MAX_NODE] = {0};
long long N,M;

long long bellman_ford(bool isSecond)
{
    bool isCg =false;
    //모든 vertex 에서 연결된 edge를 확인한다.
    //각각의 노드마다 한 번씩 수행한다.
    for(long long t=1;t<=N;t++) // 모든 엣지에 대하여
    {
        for(long long i=1;i<=N;i++)
        {
            for(long long k=0;k<E[i].size();k++)
            {
                //i까지의 거리에다가 새로운 간선 (i,k)의 weight 값을 더한다.
                long long newW = V[i] + E[i][k].weight;
                //원래 거리
                long long befW = V[E[i][k].nextNode];
                //만약에 갈수 있으면서 지금값보다 작으면 갱신한다.
                if((V[i]!=INF)&&(newW < befW))
                {
                    isCg = true;
                    if(isCg&&isSecond)
                    {
                        return isCg;
                    }
                    //i - > newnode newW값으로 갱신한다.
                    V[E[i][k].nextNode] = newW;
                } 
            }
        }
    }
    return isCg;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;
 
    // EDGE 입력받기 
    long long node1, node2, weight;
    for (long long i = 0; i < M; i++) {
        cin >> node1 >> node2 >> weight;
        E[node1].push_back(EDGE{node2, weight}); 
    }
 
    // 초기 도달 가능한 시간을 INF 으로 초기화 
    for (long long i = 2; i <= N; i++) V[i] = INF;
    
    // 벨만 포드 알고리즘 수행
    bellman_ford(false);
    
    // 두 번째 수행해서 만약 변경되는 값이 있으면, 함수에서 1이 리턴된다. 
    if (bellman_ford(true) == true) {
        cout << -1;
    }
    // 함수 리턴 값이 0이면 변한 값이 없기 때문에, 바로 값을 출력한다. 
    else {
        for (long long i = 2; i <= N; i++)
        {
            if(V[i]!=INF)
            {
                cout << V[i] <<"\n";
            }
            else
            {
                cout << -1 << "\n";
            }
            
        }
    }
 
    return 0;
}
 