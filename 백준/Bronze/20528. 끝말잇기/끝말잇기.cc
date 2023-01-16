#include <bits/stdc++.h>
using namespace std;
#define MAX 20
#define INF 299999
typedef long long ll;
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    string tmp;
    cin >> N;
    cin >> tmp;
    int ans = 1;
    for(int i=0;i<N-1;i++)
    {
        string tmp2;
        cin >> tmp2;
        if(tmp[0] != tmp2[0]){
            ans = 0;
            break;
        }
    }
    cout << ans;
}
