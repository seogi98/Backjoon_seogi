#include <iostream>
#include <queue>
using namespace std;
struct CUS
{
    int p;
    int t;
};
struct LATECUS
{
    int c;
    CUS cus;
    bool operator()(LATECUS l1, LATECUS l2)
    {
        return l1.c > l2.c;
    }
};
priority_queue<LATECUS, vector<LATECUS>, LATECUS> waitpq;
queue<CUS> readyq;
int curtime = 0;
int beforetime = 0;
int lastcus = -1;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N, T, W, M;
    cin >> N >> T >> W;
    for (int i = 0; i < N; i++)
    {
        int p, t;
        cin >> p >> t;
        readyq.push({p, t});
    }
    cin >> M;
    for (int i = 0; i < M; i++)
    {
        int p, t, c;
        cin >> p >> t >> c;
        waitpq.push({c, {p, t}});
    }
    while (beforetime < W)
    {
        beforetime = curtime;
        CUS cur = readyq.front();
        lastcus = cur.p;
        readyq.pop();
        bool isBack = false;
        if (cur.t > T)
        {
            cur.t -= T;
            curtime += T;
            isBack = true;
        }
        else
        {
            curtime += cur.t;
        }
        while (!waitpq.empty())
        {
            if(waitpq.top().c > curtime) break;
            LATECUS cur = waitpq.top();
            waitpq.pop();
            readyq.push(cur.cus);
        }
        if(isBack) readyq.push(cur);
        for (int i = beforetime; i < curtime; i++)
        {
            if(i >= W) break;
            cout << lastcus << "\n";
        }
    }
}