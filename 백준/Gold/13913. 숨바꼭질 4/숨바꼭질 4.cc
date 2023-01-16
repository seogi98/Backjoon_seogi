#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <queue>
#define MAX 100001
using namespace std;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    queue<pair<pair<int, int>,vector<int>>> q; // 다음, 횟수 , 이전
    int cur = 0;
    int T;
    int S, D; //S 수빈 D 동생
    int dA, dB, dC;
    short map[MAX] = {
        0,
    };
    cin >> S >> D;
    if(S>D)
    {
        cout << S-D << "\n";
        for(int i=S;i>=D;i--)
        {
            cout << i<< " ";
        }
        return 0;
    }
    vector<int> tmp;
    tmp.push_back(-1);
    q.push({{S, 0},tmp});
    while (!q.empty())
    {
        vector<int> Qmem;
        cur = q.front().first.first;
        T = q.front().first.second;
        Qmem = q.front().second;
        Qmem.push_back(cur);
        q.pop();
        //cout << "cur : "<< cur << endl;
        //cout << "T : "<< T<< endl;
        //cout << "D : "<< D<< endl;
        if (cur == D)
        {
            cout << T << "\n";
            for(int i=1;i<Qmem.size();i++)
            {
                cout << Qmem[i] << " ";
            }
            return 0;
        }
        dA = cur + 1;
        dB = cur - 1;
        dC = cur * 2;
        if (dA >= 0 && dA < MAX)
        {
            if (map[dA] == 0)
            {
                q.push({{dA, T + 1},Qmem});
                map[dA] = 1;
            }
        }
        if (dB >= 0 && dB < MAX)
        {
            if (map[dB] == 0)
            {
               q.push({{dB, T + 1},Qmem});
                map[dB] = 1;
            }
        }
        if (dC >= 0 && dC < MAX)
        {
            if (map[dC] == 0)
            {
               q.push({{dC, T + 1},Qmem});
                map[dC] = 1;
            }
        }
    }
}
