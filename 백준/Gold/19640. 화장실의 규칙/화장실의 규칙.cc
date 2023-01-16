#include <bits/stdc++.h>
using namespace std;
#define MAX 100010
struct cmp{
    bool operator()(pair<pair<int, int>,pair<int,bool>> p1,pair<pair<int, int>,pair<int,bool>> p2)
    {
        if(p1.first.first == p2.first.first)
        {
            if(p1.first.second == p2.first.second)
            {
                return p1.second.first > p2.second.first;
            }
            return p1.first.second < p2.first.second;
        }
        return p1.first.first < p2.first.first;
    }
};
queue<pair<pair<int, int>,bool>> q[MAX];
priority_queue<pair<pair<int, int>,pair<int,bool>>,vector<pair<pair<int, int>,pair<int,bool>>>,cmp> pq;// D , H , line , isdeka
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N, M, K;
    cin >> N >> M >> K;
    int it = 0;
    for (int i = 0; i < N; i++)
    {
        int D, H;
        cin >> D >> H;
        if (i == K)
        {
            q[it % M].push({{D, H}, true});
        }
        else
            q[it % M].push({{D, H}, false});
        it++;
    }
    int cnt = 0;
    for(int i=0;i<N&&i<M;i++)
    {
        if(q[i].empty()) continue;
        pair<pair<int, int>,bool> cur = q[i].front();
        pq.push({{cur.first.first,cur.first.second},{i,cur.second}});
    }
    while (!pq.empty())
    {
        pair<pair<int, int>,pair<int,bool>> cur = pq.top();
        pq.pop();
        int curNode = cur.second.first;
        if(q[curNode].empty()) continue;
        q[curNode].pop();
        pair<pair<int, int>,bool> qfr = q[curNode].front();
        pq.push({{qfr.first.first,qfr.first.second},{curNode,qfr.second}});
        if(cur.second.second) break;
        cnt++;
    }
    cout << cnt;
}
