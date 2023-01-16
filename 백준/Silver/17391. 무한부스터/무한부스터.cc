#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <queue>

using namespace std;
int main()
{
    queue<pair<pair<int, int>, int>> q;
    int map[301][301];
    int vst[301][301]={1,};
    int N, M;
    cin >> N >> M;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            cin >> map[i][j];
            vst[i][j] = 0;
        }
    }
    q.push(make_pair(make_pair(1, 1), 0));
   // cout << "push : " << 1 << "," << 1 << endl;
    while (!q.empty())
    {
        int R, D, V, L;
        D = q.front().first.first;
        R = q.front().first.second;
        L = q.front().second + 1;
        q.pop();
       //cout << "pop : " << D << "," << R << endl;
        if ((D == N) && (R == M))
        {
            cout << L - 1;
            return 0 ;
        }
        V = map[D][R];

        for (int i = 1; i <= V; i++)
        {
            if (R + i <= M)
            {
                if (vst[D][R + i]!=1)
                {
                    q.push(make_pair(make_pair(D, R + i), L));
                    vst[D][R+i] = 1;
                    //cout << "push : " << D << "," << R + i << endl;
                }
            }
            if (D + i <= N){
                if (vst[D + i][R]!=1)
                {
                    q.push(make_pair(make_pair(D + i, R), L));
                    vst[D+i][R] = 1;
                    //cout << "push : " << D + i << "," << R << endl;
                }
            }
        }
    }
}
