#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <queue>

using namespace std;
int main()
{
    queue<pair<pair<pair<int, int>, int>, int>> q; //(세로,가로,높이) day

    int N, M, H; //N은 세로 M은 가로  H은 높이
    int X, Y, Z;    //Y는 세로 X는 가로 Z는 높이
    int D;
    int nX, nY, nZ;
    int map[100][100][100];
    bool vst[100][100][100] = {
        false,
    };
    int dx[6] = {1, 0, -1, 0, 0, 0};
    int dy[6] = {0, -1, 0, 1, 0, 0};
    int dh[6] = {0,0,0,0,-1,1};
    int max = 0;
    cin >> M >> N >> H;
    for (int w = 0; w < H; w++)
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                cin >> map[w][i][j];
            }
        }
    }
    for (int w = 0; w < H; w++)
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {

                if (map[w][i][j] == 1)
                {
                    q.push(make_pair(make_pair(make_pair(i, j), w), 0));
                    vst[w][i][j] = true;
                }
            }
        }
    }
    while (!q.empty())
    {
        X = q.front().first.first.second;
        Y = q.front().first.first.first;
        Z = q.front().first.second;
        D = q.front().second;
        q.pop();
        // cout << X << "," <<Y <<endl;
        if (max < D)
        {
            max = D;
        }
        for (int k = 0; k < 6; k++)
        {
            nX = X + dx[k];
            nY = Y + dy[k];
            nZ = Z + dh[k];
            if (nX >= 0 && nX < M && nY >= 0 && nY < N && nZ >= 0 && nZ < H)
            {
                if (vst[nZ][nY][nX] == false && map[nZ][nY][nX] == 0)
                {
                    //cout << nY << "," <<nX<<","<<nZ <<endl;
                    q.push(make_pair(make_pair(make_pair(nY, nX), nZ), D + 1));
                    vst[nZ][nY][nX] = true;
                }
            }
        }
    }
    for (int w = 0; w < H; w++)
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                if (vst[w][i][j] == false && map[w][i][j] != -1)
                {
                    cout << "-1";
                    return 0;
                }
            }
        }
    }
    cout << max;
}
