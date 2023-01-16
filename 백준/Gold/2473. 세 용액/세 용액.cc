#include <bits/stdc++.h>
using namespace std;
#define MAX 1001
#define MAXX 201
#define INF 200000001000
typedef long long ll;
struct answer
{
    // 좌표
    ll a, b, c;

    //최소 근접값
    ll prox;
};
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll N;
    cin >> N;
    vector<ll> arr;
    for (ll i = 0; i < N; i++)
    {
        ll t;
        cin >> t;
        arr.push_back(t);
    }
    // 정답
    answer ans;
    ans.prox = INF;
    // 정렬
    sort(arr.begin(), arr.end());

    // 용액 하나를 지정한 후 나머지 두개를 두포인터를 이용해서 탐색한다.
    for (ll i = 0; i <= N - 2; i++)
    {
        // 시작
        ll start = arr[i];
        // 근접해야하는 정수
        ll goal = 0 - start;

        // 투 포인터 시작
        ll begin = i + 1;
        ll end = arr.size() - 1;
        while (begin < end)
        {
            ll sum = arr[begin] + arr[end];
            if (abs(goal - sum) < ans.prox)
            {
                ans = {arr[i], arr[begin], arr[end]};
                ans.prox = abs(goal - sum);
            }
            // 작은 경우 begin을 올려준다.
            if (sum <= goal)
            {
                begin++;
                continue;
            }
            if (sum > goal)
            {
                end--;
                continue;
            }
        }
    }
    cout << ans.a << " " << ans.b << " " << ans.c;
}