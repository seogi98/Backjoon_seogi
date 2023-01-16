#include <iostream>
#include <algorithm>
#include <string.h>
#include <queue>

using namespace std;
int result=1;
int fact(int n)
{
    if(n==0)
    {
        return 1;
    }
    else 
    {
        return fact(n-1)*n;
    }
}
int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    cout << fact(N);
    
}