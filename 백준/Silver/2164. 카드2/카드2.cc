#include<iostream>
#include<string.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<stdlib.h>

using namespace std;

int main(void)
{
    queue<int> cd;
    int N;
    cin >> N;
    for(int i=1;i<=N;i++)
    {
        cd.push(i);
    }
    while(cd.size()!=1)
    {
        cd.pop();
        cd.push(cd.front());
        cd.pop();
    }
    cout << cd.front();
}
