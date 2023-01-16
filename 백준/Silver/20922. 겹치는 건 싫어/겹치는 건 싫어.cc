#include<bits/stdc++.h>
using namespace std;
#define MAX 200010
int dup[MAX];
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N,K;
    cin >> N >> K;
    int cnt =0;
    int mx =0;
    vector<int> V;
    for(int i=0;i<N;i++)
    {
        int t;
        cin >> t;
        V.push_back(t);
    }
    int start =0;
    int end =0;
    while(end < N)
    {
        int cur = V[end];
        dup[cur] ++;
        while(dup[cur] > K){
            dup[V[start]]--;
            start++;
        }
        end++;
        mx = max(mx,end-start);
    }
    cout << mx;
}