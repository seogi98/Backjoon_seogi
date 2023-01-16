#include <iostream>
#include <algorithm>
#include <string.h>
#include<queue>
#define MAX 10000001
using namespace std;

int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int N;
    int A[51];
    int B[51];
    int result=0;
    cin >> N;
    for(int i=0;i<N;i++)
    {
        cin >> A[i];
    }
    for(int i=0;i<N;i++)
    {
        cin >> B[i];
    }
    sort(A,A+N);
    sort(B,B+N);
    for(int i=0;i<N;i++){
        result+=A[i]*B[N-i-1];
    }
    cout << result;
}