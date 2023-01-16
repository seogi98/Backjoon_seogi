#include <bits/stdc++.h>
using namespace std;
#define MAX 200010
#define INF 999999999

int N;              //사람수
int M;              // 유포자 수
vector<int> V[MAX]; // 관계
vector<int> D;      //처음 유포자
int bl[MAX];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    memset(bl, -1, sizeof(bl)); // 믿는지 여부
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        while (1)
        {
            int fred;
            cin >> fred;
            if (fred == 0)
            {
                break;
            }
            V[i].push_back(fred);
        }
    }
    cin >> M;
    for (int i = 0; i < M; i++)
    {
        int diff;
        cin >> diff;
        D.push_back(diff);
        bl[diff] = 0;
    }
    queue<pair<int, int>> q; // nextnode, time
    for (int i = 0; i < D.size(); i++)
    {
        q.push({D[i], 0});
    }
    while (!q.empty())
    {
        int curNode = q.front().first;
        int curTime = q.front().second;
        if (bl[curNode] != -1)
        {
            bl[curNode] = min(curTime, bl[curNode]);
        }
        else
        {
            bl[curNode] = curTime;
        }
        q.pop();
        for (int i = 0; i < V[curNode].size(); i++)
        {
            int nextNode = V[curNode][i];
            if (bl[nextNode] >= 0)
                continue;
            int isRumer = 0;
            for (int i = 0; i < V[nextNode].size(); i++)
            {
                if (bl[V[nextNode][i]] >= 0)
                    isRumer++;
            }
            if(!(isRumer||V[nextNode].size())) 
                continue;
                
            if (((double)V[nextNode].size() / isRumer) <= 2)
            {
                q.push({nextNode, curTime + 1});
            }
        }
    }
    for (int i = 1; i <= N; i++)
    {
        cout << bl[i] << " ";
    }
}