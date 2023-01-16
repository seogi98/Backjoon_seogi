#include <bits/stdc++.h>
#define MAX 15
#define INF 987654321
using namespace std;
int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    priority_queue<int> pq;
    int N;
    cin >> N;
    int result=0;
    for(int i=0;i<N;i++)
    {
        int T;
        cin >> T;
        pq.push(-T);
    }
    while(pq.size()>=2)
    {
        int node1 = -pq.top();
        pq.pop();
        int node2 = -pq.top();
        pq.pop();
        result +=node1 +node2;
        pq.push(-(node1+node2));
    }
    cout << result;
}                                                             