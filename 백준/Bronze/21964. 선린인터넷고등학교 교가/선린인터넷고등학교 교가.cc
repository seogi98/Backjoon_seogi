#include<bits/stdc++.h>
#define MAX 1000000
using namespace std;
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    string str;
    cin >> str;
    cout << str.substr(N-5,N);
}