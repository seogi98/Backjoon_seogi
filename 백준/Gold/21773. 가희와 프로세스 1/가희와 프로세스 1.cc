#include<bits/stdc++.h>
using namespace std;
#define MAX 101
// 이것은 i번째 process의 id가 Ai이고, 
//프로세스 id가 실행을 마치는 데 필요한 시간이 Bi초이고,
// 초기 우선 순위가 Ci임을 의미합니다.
struct process{
    int id;
    int time;
    int order;
    bool operator()(process p1,process p2){
        if(p1.order == p2.order){
            return p1.id > p2.id;
        }
        return  p1.order < p2.order;
    }
};
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,t;
    cin >> t >> n;
    priority_queue<process,vector<process>,process> pq;
    for(int i=0;i<n;i++){
        int a,b,c;
        cin >> a >> b >> c;
        pq.push({a,b,c});
    }
    for(int i=0;i<t;i++){
        // select
        if(pq.empty()) break;
        process cur = pq.top();
        pq.pop();
        cout << cur.id << "\n";
        cur.order --;
        cur.time --;
        if(cur.time == 0) continue;
        pq.push(cur);
    }
}
