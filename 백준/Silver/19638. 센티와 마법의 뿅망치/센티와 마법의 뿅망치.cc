#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N,H,T;
    bool isY=true;
    cin >> N >> H >> T;
    priority_queue<int> G;
    for(int i=0;i<N;i++)
    {
        int tmp;
        cin >> tmp;
        G.push(tmp);
    }    
    int cnt=0;
    while(H <= G.top())
    {
        cnt++;
        if(cnt >T)
        {
            isY = false;
            break;
        }
        int fr = G.top();
        G.pop();
        if(fr == 1)
        {
            G.push(1);
            continue;
        }
        G.push((fr/2));
    }
    if(isY)
    {
        cout << "YES\n";
        cout << cnt;
    }
    else
    {
        cout << "NO\n";
        cout << G.top();
    }

}
