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
    int N,M,tmp;
    bool A[MAX]={false,};
    bool dA[MAX]={false,};
    bool B[MAX]={false,};
    cin >> N;
    for(int i=1;i<=N;i++)
    {
        cin >> tmp;
        if(tmp>=0){
            A[tmp]=true;
        }
        else
        {
            dA[-tmp]=true;
        }
    }
    cin >> M;
    for(int i=1;i<=M;i++)
    {
        cin >>tmp;
        if(tmp>=0)
        {
            cout << A[tmp]<<" ";
        }
        else
        {
            cout <<dA[-tmp]<<" ";
        }
        
    }
    
    
}