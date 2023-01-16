#include <bits/stdc++.h>
using namespace std;
#define MAX 1001
#define MAXX 201
int ans=0;
void solution(int len, pair<int, int> P, int sum)
{
    if(len == 0)
    {
        ans = sum;
        return;
    }
    int y = P.first;
    int x = P.second;
    int sub = pow(2, len - 1);
    int com = sub * sub;
    if (x >= sub)
    {
        x-=sub;
        sum+=com;
    }
    if (y >= sub)
    {
        y-=sub;
        sum+=com*2;
    }
    solution(len-1,{y,x},sum);
}
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N, R, C;
    cin >> N >> R >> C;
    solution(N,{R,C},0);
    cout << ans;
}