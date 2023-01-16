#include <bits/stdc++.h>
using namespace std;
#define MAX 101000
#define DIV 10007
typedef long long ll;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    vector<int> V;
    for(int i=0;i<N;i++)
    {
        int t;
        cin >> t;
        V.push_back(t);
    }
    sort(V.begin(),V.end());
    int x;
    cin >> x;
    int begin = 0;
    int end = V.size()-1;
    int ans=0;
    while(begin < end)
    {
        int sum = V[begin] + V[end];
        if(sum == x)
        {
            ans++;
        }
        if(sum <= x)
        {
            begin++;
        }
        if(sum>x)
        {
            end--;
        }
    }
    cout << ans;
}
