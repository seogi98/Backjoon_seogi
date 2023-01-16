#include<bits/stdc++.h>
using namespace std;
// 이진탐색
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    vector<int> V;
    for(int i=0;i<N;i++){
        int tmp;
        cin >> tmp;
        V.push_back(tmp);
    }
    sort(V.begin(),V.end());
    int M;
    cin >> M;
    for(int i=0;i<M;i++){

        int guess;
        cin >> guess;
        int ans =0;
        int start = 0;
        int end = M;
        while(start <= end){
            int mid = (start+end)/2;
            if(V[mid] < guess){
                start  = mid+1;
            }
            if(V[mid] > guess){
                end = mid-1;
            }
            if(V[mid] == guess){
                ans = 1;
                break;
            }
        }
        cout << ans << '\n';
    }
}