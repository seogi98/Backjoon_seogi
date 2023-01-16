#include<bits/stdc++.h>
using namespace std;
#define INF 1000000001
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    long long start = 0;
    long long end = INF;
    long long x,y;
    cin >> x >> y;
    long long z = y*100/x;
    long long mn =INF;
    if(z >=99) {
        cout << -1;
        return 0;
    }
    while(start <= end)
    {
        long long mid = (start+end)/2;
        long long nx = x+mid;
        long long ny = y+mid;
        long long nz = ny*100/nx;
        //승률이 크면 횟수를 줄여야한다.
        if(nz > z)
        {
            end = mid-1;
            mn = min(mn,mid);
            continue;
        }
        start = mid+1;
    }
    cout << mn;
}
