#include <iostream>
#include <algorithm>
#include <string.h>
#include<queue>
#include<vector>
#define MAX 10000001
using namespace std;


int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int N;
    int A[100001];
    cin >>N;
    for(int i=0;i<N;i++)
    {
        cin >> A[i];
    }
    sort(A,A+N);
    for (int i = 0; i < N; i++)
    {
        if(i>0&&A[i]==A[i-1])
        {
            continue;
        }
        cout << A[i] << " ";
        
    }
    
}