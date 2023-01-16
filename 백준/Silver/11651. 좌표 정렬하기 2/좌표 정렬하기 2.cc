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
    int x,y;
    cin>> N;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    for(int i=0;i<N;i++)
    {
        cin >> y >> x;
        pq.push({x,y});
    }
    while(!pq.empty()){
        cout << pq.top().second << " "<< pq.top().first<<"\n";
        pq.pop();
    }
    
}