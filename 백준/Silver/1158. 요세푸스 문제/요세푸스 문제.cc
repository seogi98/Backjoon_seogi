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
    int N,K;
    queue<int> q;

    cin >> N >> K;
    for(int i=1;i<=N;i++)
    {  
        q.push(i);
    }
    cout << "<";
    N=N-1;
    while(N--)
    {
        for(int i=0;i<K-1;i++)
        {
            q.push(q.front());
            q.pop();
        }  
        cout << q.front()<<", ";
        q.pop();
    }
    cout <<q.front() <<">";     
}