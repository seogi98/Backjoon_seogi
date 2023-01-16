#include <bits/stdc++.h>
using namespace std;
#define MAX 200010
#define INF 2e31
// MAX값 기록해 놓고
// dp[i] => 자기
// dp[i] = dp[i-1]+1+arr[i]-
bool dup[MAX];
int arr[MAX];
int arr2[MAX];
int dp[MAX];
int mmx[MAX];
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    int mx = 0;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
        arr2[i] = arr[i] - i;
        mx = max(arr2[i], mx);
    }
    priority_queue<int> pq;
    for(int i=N-1;i>0;i--){
        pq.push(arr2[i]);
        mmx[i-1] = pq.top();
    }
    dp[0] = arr[0];
    //더 작은 애들이랑 싸웟을 경우
    for (int i = 1; i < N; i++)
    {
        if (arr[i] == arr[i - 1])
        {
            dp[i] = dp[i - 1];
            dup[i] = true;
            continue;
        }
        dp[i] = arr[i] + i;
    }
    int idx = -1;
    for (int i = 0; i < N; i++)
    {
        // cur == arr[i];
        int cur = dp[i];
        if(dup[i]) continue;
        if (cur > mmx[i]+i+1)
        {
            idx = i;
            break;
        }
    }
    if (idx == -1)
    {
        cout << -1;
        return 0;
    }
    for (int i = idx; i < N; i++)
    {
        if (dup[i])
            continue;
        cout << i + 1 << " ";
    }
}