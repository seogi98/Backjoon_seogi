#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int ans = 0;
int num[100];
int pl[100];
int mi[100];
int N;
void dfs(int x)
{
    if (x == N)
    {
        ans++;
        return;
    }
    for (int y = 0; y < N; y++)
    {
        if (num[y] == false && pl[x + y] == false && mi[x - y + 14] == false)
        {
            num[y] = pl[x + y] = mi[x - y + 14] = true;
            dfs(x + 1);
            num[y] = pl[x + y] = mi[x - y + 14] = false;
        }
    }
}
int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> N;
    dfs(0);
    cout << ans << "\n";
}