#include <bits/stdc++.h>
using namespace std;
#define MAX 1000011
#define INF 1000000000001
typedef long long ll;
void ety()
{
    cout << "EMPTY\n";
}
ll popMax(priority_queue<pair<ll, ll>> &mx,bool *vst)
{
    if (mx.empty()) return INF;
    ll curIdx = mx.top().second;
    while (vst[curIdx] && !mx.empty())
    {
        mx.pop();
        curIdx = mx.top().second;
    }
    if (mx.empty()) return INF;
    vst[curIdx] = true;
    return mx.top().first;
}
ll popMin(priority_queue<pair<ll, ll>> &mn,bool *vst)
{
    if (mn.empty()) return INF;
    ll curIdx = mn.top().second;
    while (vst[curIdx] && !mn.empty())
    {
        mn.pop();
        curIdx = mn.top().second;
    }
    if (mn.empty()) return INF;
    vst[curIdx] = true;
    return -mn.top().first;
}
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll T;
    cin >> T;
    while (T--)
    {
        // 이미 뽑아낸 노드이면 스킵한다.
        bool vst[MAX];
        memset(vst, false, sizeof(vst));
        // 최대값
        priority_queue<pair<ll, ll>> mx;
        // 최소값 => 음수 input
        priority_queue<pair<ll, ll>> mn;

        ll k;
        cin >> k;
        ll idx = 1;
        for (ll i = 0; i < k; i++)
        {
            char op;
            ll n;
            cin >> op >> n;
            if (op == 'I')
            {
                mx.push({n, idx});
                mn.push({-n, idx});
                idx++;
                continue;
            }
            if (op == 'D')
            {
                //최대값
                if (n == 1)
                {
                    popMax(mx,vst);
                }
                //최대값
                if (n == -1)
                {
                    popMin(mn,vst);
                }
                continue;
            }
        }
        ll mxtop = popMax(mx,vst);
        ll mntop = popMin(mn,vst);
        if(mxtop == INF && mntop ==INF)
        {
            ety();
            continue;
        }
        if(mxtop == INF || mntop ==INF)
        {
            int tmp = min(mxtop,mntop);
            cout <<  tmp << " " << tmp << "\n";
            continue;
        }
        cout << mxtop << " " << mntop << "\n";
    }
}