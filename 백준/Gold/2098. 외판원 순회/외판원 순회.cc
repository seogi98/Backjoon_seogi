#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <stdlib.h>

using namespace std;
#define INF 98754321
typedef long long ll;
int map[17][17];     //처음에 데이터를 넣는 map
int DP[17][1 << 16]; // DP 데이터 [here][visit]
int N;               //갯수

int TSP(int here, int visit) // 제귀로 접근한다.
{
    //(기저) 만약에 DP[here][visit]값에 데이터가 이미 있는경우 그값 return
    if (DP[here][visit] != -1)
    {
        return DP[here][visit];
    }
    //만약에 모든 섬을 방문하였을 경우
    if (visit == (1 << N) - 1)
    {
        //원래섬으로 돌아갈수 없을경우 return INF (0으로하면 최솟값으로 잡혀버린다.)
        if (map[here][0] == 0)
        {
            return INF;
        }
        //있을경우 DP에 값 저장
        return DP[here][visit] = map[here][0];
    }
    //없을경우이므로 최대값을 저장해놓는다.
    DP[here][visit] = INF;
    //DP[here][visit]값에 INF넣고 접근한다.
    for (int i = 0; i < N; i++)
    {
        //i 섬을 방문하였거나 가는길이 0일경우 SKIP
        if ((visit & (1 << i)) || !map[here][i])
        {
            continue;
        }
        //갈수 있을경우 원래 DP값과 현제값중 min 값을 DP에 저장한다.
        //중간에 다른섬을 들러서 가는 경우와 그냥 직진으로 가는 경우중 min 값을 저장한다.
        DP[here][visit] = min(DP[here][visit], (TSP(i, visit | (1 << i)) + map[here][i]));
    }
    return DP[here][visit];
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> map[i][j];
        }
    }
    memset(DP, -1, sizeof(DP));
    cout << TSP(0,1<<0);
    return 0;
}
