#include <iostream>
#include <algorithm>
#include <string.h>
#include <queue>
#include <vector>

using namespace std;

int N;
vector<pair<int,int>> v;

void hanoi(int num,int start ,int mid,int end)
{
    if(num == 0)
    {
        return ;
    }
    hanoi(num-1 , start,end,mid);
    v.push_back({start,end});
    hanoi(num-1,mid,start,end);
}
int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;
    hanoi(N,1,2,3);
    cout << v.size()<<endl;;
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i].first << " " << v[i].second<<"\n";
    }
    
    return 0;
    
}