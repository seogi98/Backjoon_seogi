#include <string>
#include <math.h>
#include <vector>
#include <iostream>
#include<algorithm>
#include<queue>

using namespace std;

priority_queue<int,vector<int>,less<int>> pq;

int N;

int main(void)
{
    int N;
    cin >> N;
    vector<int> v;

    for(int i=0;i<N;i++)
    {
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }
    sort(v.begin(),v.end());
        do
    {
        int result=0;
        for(int i=1;i<N;i++)
        {
            result+=abs(v[i-1]-v[i]);
        }
        pq.push(result);
    }while(next_permutation(v.begin(),v.end()));
    cout << pq.top();
}