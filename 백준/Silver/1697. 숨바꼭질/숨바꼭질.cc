#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <queue>
#define MAX 100001
using namespace std;

int main()
{
    queue<pair<int, int>> q;
    int cur = 0;
    int T;
    int S, D; //S 수빈 D 동생
    int dA, dB, dC;
    short map[MAX] = {
        0,
    };
    cin >> S >> D;
    q.push(make_pair(S, 0));
    while (!q.empty())
    {
        cur = q.front().first;
        T = q.front().second;
        q.pop();
        //cout << "cur : "<< cur << endl;
        //cout << "T : "<< T<< endl;
        //cout << "D : "<< D<< endl;
        if (cur == D)
        {
            cout << T;
            return 0;
        }
        dA = cur + 1;
        dB = cur - 1;
        dC = cur * 2;
        if (dA >= 0 && dA < MAX)
        {
            if (map[dA] == 0)
            {
                q.push(make_pair(dA, T + 1));
                map[dA] = 1;
            }
        }
        if (dB >= 0 && dB < MAX)
        {
            if (map[dB] == 0)
            {
                q.push(make_pair(dB, T + 1));
                map[dB] = 1;
            }
        }
        if (dC >= 0 && dC < MAX)
        {
            if (map[dC] == 0)
            {
                q.push(make_pair(dC, T + 1));
                map[dC] = 1;
            }
        }
    }
}
