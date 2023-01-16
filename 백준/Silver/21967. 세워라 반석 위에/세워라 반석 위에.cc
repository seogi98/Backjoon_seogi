#include <bits/stdc++.h>
#define MAX 1000000
using namespace std;
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    vector<int> arr(N,0);
    for(int i=0;i<N;i++){
        cin >> arr[i];
    }
    int mx = 0;
    // (1,2,3) ~ (8,9,10) 까지 체크한다
    for(int i=1;i<=8;i++){
        int idx =0;
        for(int j=0;j<N;j++){
            int cur = arr[j];
            if(i > cur || i + 2 < cur){
                idx = 0;
                continue;
            }
            idx++;
            mx = max(mx,idx);
        }
    }
    cout << mx;
}