#include <iostream>
#include <algorithm>
#include <vector>
#include<math.h>
using namespace std;
#define MAX 1000001

bool prime[MAX]={false,};
int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int A,B;
    int m,M,min,max;
    cin >> A >>B;
    m = A<B?A:B;
    M = A>B?A:B;
    for(int i=m;i>=1;i--)
    {
        if(!(M%i)&&!(m%i))
        {
            min  = i;
            cout << min<<"\n";
            break;
        }
    }

    for(int i=m;i<=m*M;i+=m)
    {
        if(!(i%m)&&!(i%M))
        {
            cout << i;
            break;
        }
    }



}