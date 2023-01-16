#include <bits/stdc++.h>
using namespace std;
#define MAX 100
typedef long long ll;
// 누적합
ll culSum[MAX];
ll arr[MAX];
// 이때까지 나온 1,2,3,4 의 dp를 저장한다.
ll dp[MAX][5];
// 1,2,3,4의 개수를 저장한다.
ll num[5];
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    bool checkZero = true;
    // 누적 합의 배수를 골라냄
    vector<ll> sel;
    ll N;
    cin >> N;
    for (ll i = 0; i < N; i++)
    {
        cin >> arr[i];
        if(arr[i] != 0){
            checkZero = false;
        }
        if (i == 0)
        {
            culSum[0] = arr[0];
            continue;
        }
        culSum[i] += culSum[i - 1] + arr[i];
    }
    if(culSum[N-1]%4 != 0){
        cout << 0;
        return 0;
    }
    // 4개의 구역으로 나누니까 누적합에서 4등분
    ll avg = culSum[N - 1] / 4;
    // 증가하는 부분 수열 개수
    for (ll i = 0; i < N; i++)
    {
        if(avg == 0){
            if(culSum[i] == 0){
                sel.push_back(0);
            }
            continue;
        }
        // 만약에 나누어 질 경우
        if (culSum[i] % avg == 0 && abs(culSum[i] / avg) <= 4 && abs(culSum[i] / avg) >= 0)
        {
            sel.push_back(abs(culSum[i] / avg));
        }
    }
    ll ans=0;
    if(culSum[N-1] == 0){
        if(sel.size() >=3)
        {
            // N-1C3
            ans = ((sel.size()-1)*(sel.size()-2)*(sel.size()-3))/6;
        }
        else
        {
            ans = 0;
        }
        cout << ans;
        return 0;
    }
    for (ll i = 0; i < sel.size(); i++)
    {
        ll cur = sel[i];
        if(cur == 1){
            dp[i][cur] = 1;
            continue;
        }
        for(ll j=0;j<i;j++)
        {
            ll pre = sel[j];
            if(pre == cur-1){
                dp[i][cur] += dp[j][pre];
            }
        }
        if(cur == 4){
            ans+=dp[i][cur];
        }
    }
    cout << ans;
}