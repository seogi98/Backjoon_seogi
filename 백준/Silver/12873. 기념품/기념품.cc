#include <string>
#include <math.h>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <string.h>
#include <vector>
using namespace std;

int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    long long N;
    cin >> N;
    queue<long long> v;
    for (long long i = 1; i <= N; i++)
    {
        v.push(i);
    }
    for (long long i = 1; i < N; i++)
    {
        long long cir = (i*i*i)%v.size();
        if(cir ==0)
        {
            cir = v.size();
        }
        for(long long j=1;j<cir;j++)
        {
            v.push(v.front());
            v.pop();
        }
        v.pop();
    }
    cout << v.front();
}