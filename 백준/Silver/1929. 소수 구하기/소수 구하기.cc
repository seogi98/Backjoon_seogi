#include <iostream>
#include <algorithm>
#include <vector>
#include<math.h>
using namespace std;
#define MAX 1000001

bool prime[MAX]={false,};
int main(void)
{
    //cin.tie(NULL);
    //ios::sync_with_stdio(false);
    int N;
    int result=0;
    int st,ed;
    prime[1] = true;
    cin >> st >> ed;
    for(int i=2;i<=ed;i++)
    {
        if(prime[i]==false)
        {
            for(int j=i*2;j<=ed;j+=i)
            {
                prime[j]=true;
            }
        }
    }
    for(int i=st;i<=ed;i++)
    {
        if(prime[i]==false)
        {
            cout << i << "\n";
        }
    }
}