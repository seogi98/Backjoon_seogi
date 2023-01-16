#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;


int N,K;
int arr[21];
priority_queue<int,vector<int>,greater<int>> pq;


void findB(int start,int end,int n,int result)
{
    if(n==K)
    {
        //cout << "start : " << start << " end : " << end << " arr["
        //<<n<<"] : " << arr[n] << " result : "  << result<<endl;
        pq.push(result);
        return;
    }

    if(arr[n]<start)
    {
       result+=start-arr[n];
        findB(arr[n],end,n+1,result);
    }
    else if(start<=arr[n]&&arr[n]<=end)
    {
        findB(start,arr[n],n+1,result+abs(end-arr[n]));
        findB(arr[n],end,n+1,result+abs(arr[n]-start));
    }
    else
    {
        result+=arr[n]-end;
        findB(start,arr[n],n+1,result);
    }
}
int main(void)
{
    int A,B;
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;
    cin >> A >> B>>K;
    for(int i=0;i<K;i++)
    {
        cin >> arr[i];
    }
    findB(A,B,0,0);
    //while(!pq.empty())
    {
        cout << pq.top();
        //pq.pop();
    }
}