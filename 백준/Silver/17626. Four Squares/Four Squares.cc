#include <bits/stdc++.h>
using namespace std;
#define MAX 50001
int vst[MAX];
int main(void)
{
    int N;
    cin >> N;
    queue<pair<int,int>> q;
    q.push({N,0});
    while(!q.empty())
    {
        int cur = q.front().first;
        int count = q.front().second;
        q.pop();
        if(cur == 0) {
            cout << count;
            return 0;
        }
        for(int i=1;i<=floor(sqrt(cur));i++){
            if(vst[cur-i*i]) continue;
            vst[cur-i*i] = true;
            q.push({cur-i*i,count+1});
        }
    }
}